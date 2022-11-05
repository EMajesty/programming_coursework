using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

using System.IO;

using System.Net;
using System.Net.Sockets;

namespace SpedeSgamesRecords
{
    /**
     * class for Records's's Main method
     */
    class Program
    {
        // Main method should be public
        public static void Main(string[] args)
        {
            Records records = new Records(); // create the game object

            records.Play(); // play the game and wait until stop
        }
    }
    /**
     * This class handles the game records
     */
    class Records
    {
        // an empty constructor
        public Records()
        {

        }
        // method for asking the records
        public void Play()
        {
            bool play = true; // for continuing the play

            string msg;

            Input("Press enter when start show records!");

            // sender object
            Sender sender = new Sender();

            string cmd;
            int top;

            // message loop
            while (play)
            {
                // here the UI for asking top records
                // and server stopping
                cmd = Input("Please give the count of top records: ");

                if(cmd != "stop")
                {
                    sender.WriteLine("rec: " + cmd);
                    msg = sender.ReadLine();
                    Console.WriteLine(msg);
                    string[] parts = msg.Split(new string[] { ": ", ", " }, StringSplitOptions.None);
                    top = int.Parse(parts[1]);
                    for(int i = 0; i < top; i++)
                    {
                        Console.WriteLine(sender.ReadLine());
                    }
                }
                else 
                {
                    sender.WriteLine(cmd);
                    play = false;
                }
            }
        }
        // method for prompted input
        protected string Input(string prompt)
        {
            Console.Write(prompt);
            return Console.ReadLine();
        }
    }
    /**
     * class definiton for sending results to the server
     */
    class Sender
    {
        // attributes
        TcpClient client;
        StreamReader rdr;
        StreamWriter wtr;

        // constructor
        public Sender(string host = "localhost", int port = 12345)
        {
            try
            {
                // initialize attributes
                client = new TcpClient(host, port); // connect to the server
                rdr = new StreamReader(client.GetStream());
                wtr = new StreamWriter(client.GetStream());
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sender constructor: {ex.Message}");
            }
        }
        // destructor
        ~Sender()
        {
            client.Close(); // close connection
        }
        // send method
        public void WriteLine(string s)
        {
            try
            {
                wtr.WriteLine(s);
                wtr.Flush();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sender WriteLine: {ex.Message}");
            }
        }
        public string ReadLine()
        {
            try
            {
                return rdr.ReadLine();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Sender ReadLine: {ex.Message}");
            }
            return "";
        }
    }
}
