
/**
 * This in codetemplate for SpedeSgames server.
 * There is examples for file based and database based
 * records saving.
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

using System.IO;

using System.Net;
using System.Net.Sockets;

using System.Data.SqlClient; // SQL Server
using System.Data;

namespace SpedeSgamesServer
{
    /**
     * class for Server's Main method
     */
    class Program
    {
        Main method should be public and async
        public static async Task Main(string[] args)
        {
            // create Server object
            Server server = new Server();

            // call Listen task asyncronously and wait it's end
            await server.Listen();
        }
    }
    /**
     * class for handling SpedeSgames's results
     * 
     * There is also an example for Sql database connection
     */
    class Server
    {
        // attributes
        TcpListener listener;       // Listener object
        protected bool go = true;   // flag for listening loop
        string fname;               // file name for results

        // for database handlind (Sql Server)
        SqlConnection sql;          // for connection handlind
        SqlCommand cmd;             // for sql commands executing

        // constructor
        public Server(string fname = "records.txt", int port = 12345)
        {
            listener = new TcpListener(IPAddress.Any, port);
            this.fname = fname;

            //Console.WriteLine($"{DateTime.Now}Server started");
            try // for error handling
            {
                // open connection to MySql server
                sql = new SqlConnection(
                    @"Server=tcp:ds20-dbserver.database.windows.net,1433;
                    Initial Catalog=ds20_db;User ID=turutimo;Password=Koodaus1;
                    Connection Timeout=30");
                sql.Open();
                //Console.WriteLine($"{DateTime.Now}: Connected to database!");

                // create the records table
                // this generates an exeption if the table exists
                cmd = new SqlCommand( // table creation statement
                    @"create table ds20_records_turutimo (
                    name varchar(20),
                    time varchar(20),
                    result decimal(5,2) not null,
                    target decimal(5,2) not null,
                    primary key (name, time)
                    )", sql);
                cmd.ExecuteNonQuery(); // execute table creation statement
            }
            catch (Exception ex)
            {   // if an error exists
                // handle the exception if necessary
            }
        }
        // listening loop task
        public async Task Listen()
        {
            List<Task> tasks = new List<Task>();    // for task infos
            TcpClient client;   // for connection handling from accept
            listener.Start();   // start listening
            
            try
            {
                // listening loop while go flag is true
                while (go)
                {
                    // start waiting connections
                    client = await listener.AcceptTcpClientAsync();

                    // create task for connection
                    tasks.Add(HandleConnection(client));

                    // how to remove stopped tasks from list
                }
            }
            catch (Exception ex)
            {
                // this exception based loop ending works
                // in Windows but not on bott's mono environment
            }
            listener.Stop();
            // can we wait until all tasks have stopped
        }
        // task for communicating
        protected async Task HandleConnection(TcpClient client)
        {
            StreamReader rdr = new StreamReader(client.GetStream()); // get the reader stream
            StreamWriter wtr = new StreamWriter(client.GetStream()); // writer
            string msg; // message buffer for reading

            // message handling loop
            do
            {
                // read message from client's stream
                msg = rdr.ReadLine();

                // handle not empty messages - an empty message ends communication
                if (msg != "")
                {
                    // message format like:
                    // '<cmd>: <command parameters>'
                    // cmds: res - save record
                    //       rec <top> - get top records
                    //       stop - stop server listening and executing

                    // split the message for getting
                    // command and parameters
                    string[] parts = msg.Split(new string[] { ": ", ", " }, StringSplitOptions.None);

                    // handle commands
                    switch (parts[0])
                    {
                        // records from the database
                        case "rec":
                            // add here your own code for records getting
                            break;
                        // results from the client
                        case "res":
                            // we need to save the results to the database table
                            try
                            {
                                // insert statement definition
                                cmd.CommandText = String.Format(new System.Globalization.CultureInfo("en-US"),
                                    "insert into ds20_records_turutimo values " +
                                    "('{0}', '{1}', {2:0.00}, {3:0.00})",
                                    parts[1], parts[4], double.Parse(parts[2]), double.Parse(parts[3]));
                                cmd.ExecuteNonQuery(); // execute the insertion
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine(ex.Message);
                            }

                            // write to the result file
                            File.AppendAllText(fname, $"{msg}\r\n");
                            break;
                        // stop the listener loop
                        case "stop":
                            go = false;         // seg go flad to be false for stopping
                            listener.Stop();    // throw an exception for accept

                            // send empty message to listener for stopping
                            // using temporary connection object
                            TcpClient cclient = new TcpClient("localhost", 12345);
                            StreamWriter cwtr = new StreamWriter(cclient.GetStream());
                            cwtr.WriteLine(); cwtr.Flush();
                            cclient.Close();    // close temporary connection object
                            break;
                    }
                }
            } while (msg != ""); // until the empty msg

            client.Close();     // close task's connection object
        }
    }
}
