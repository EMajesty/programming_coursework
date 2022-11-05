using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace Server
{
    class Program
    {
        public static TcpListener server = null;

        public static async Task Main(string[] args)
        {
            
            int port = 12345;
            IPAddress addr = IPAddress.Parse("127.0.0.1");

            server = new TcpListener(addr, port);
            server.Start();
            try
            {
                while (true)
                {
                    TcpClient client = await server.AcceptTcpClientAsync();

                    ClientCommunicator(client);
                }
            }
            catch { }
            
            Console.WriteLine("Server stopped");
        }

        public static async Task ClientCommunicator(TcpClient client)
        {
            NetworkStream stream = client.GetStream();
            String data;
            StreamReader rdr = new StreamReader(stream); // we can use now ReadLine
            StreamWriter wtr = new StreamWriter(stream); // we can use now Writeline and Flush

            while (true)
            {
                data = rdr.ReadLine(); // read line from client network stream

                switch (data)
                {
                    case "":
                        client.Close();
                        break;

                    case "__stop__":
                        client.Close();
                        server.Stop();
                        break;

                    default:
                        Console.WriteLine($"Got: {data}");
                        // moderate data
                        data = data.Replace("LAMK", "LAB");
                        data = data.Replace("Saimia", "LAB");
                        data = data.Replace("Lahden ammattikorkeakoulu", "LAB-ammattikorkeakoulu");
                        data = data.Replace("Saimaan ammattikorkeakoulu", "LAB-ammattikorkeakoulu");

                        Console.WriteLine($"Adapted: {data}");

                        wtr.WriteLine(data); // send it back
                        wtr.Flush();
                        break;
                }
            }
        }
    }
}
