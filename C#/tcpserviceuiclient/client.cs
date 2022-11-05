using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.IO;

namespace Client
{
    class Program
    {
        public static void Main(string[] args)
        {
            TcpClient client;
            NetworkStream stream;
            StreamReader rdr;
            StreamWriter wtr;
            String smsg;
            int port = 12345;
            bool loop = true;

            while (true)
            {
                try
                {
                    client = new TcpClient();
                    client.Connect("localhost", port);
                    break;
                }
                catch { }
            }

            while(loop)
            {
                Console.Write("Give a line: ");
                smsg = Console.ReadLine();

                
                stream = client.GetStream();
                rdr = new StreamReader(stream);
                wtr = new StreamWriter(stream);

                
                
                switch (smsg)
                {
                    case "__stop__":
                        wtr.WriteLine(smsg);
                        wtr.Flush();
                        client.Close();
                        loop = false;
                        break;

                    case "":
                        wtr.WriteLine(smsg);
                        wtr.Flush();
                        client.Close();
                        loop = false;
                        break;

                    case "__file__":
                        string line;
                        string filename;
                        Console.WriteLine("Give a file name: ");
                        filename = Console.ReadLine();
                        System.IO.StreamReader file = new System.IO.StreamReader(filename);
                        while((line = file.ReadLine()) != null)
                        {
                            wtr.WriteLine(line);
                            wtr.Flush();
                            Console.WriteLine(rdr.ReadLine());
                        }
                        break;

                    default:
                        wtr.WriteLine(smsg);
                        wtr.Flush();
                        Console.WriteLine(rdr.ReadLine());
                        break;
                }       
            }
        }
    }
}
