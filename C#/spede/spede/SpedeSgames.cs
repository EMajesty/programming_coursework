using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

using System.IO;

using System.Net;
using System.Net.Sockets;

namespace SpedeSgames
{
    /**
     * class for Sgames's's Main method
     */
    class Program
    {
        // Main method should be public
        public static void Main(string[] args)
        {
            Sgame game = new Sgame();   // create the game object

            game.Prepare();             // prepare the game to be ready

            game.Play();                // play the game - wait until stop
        }
    }
    /**
     * This class handles the game
     */
    class Sgame
    {
        // attributes
        string nickname; // for players identification
        int target;         // target time for estimate

        // constructors
        public Sgame()
        {
            // attributes initializations
            nickname = "";
            target = 2; // 2 seconds
        }
        // method for preparing the game ready (UI)
        public void Prepare()
        {
            Console.WriteLine("Wellcome to play SpedeSgame!");
            nickname = Input("Give your nickname: ");
        }
        // method for playing the game
        public void Play()
        {
            bool play = true; // for continuing the play

            Random r = new Random(); // for delay

            DateTime start, stop;   // variables for time measuring

            double time, result;    // result time and result difference

            string m;               // 

            // sender object
            Sender sender = new Sender();

            // play loop
            while (play)
            {
                Input("Push enter when you are ready!");

                Console.WriteLine("Wait until time starts!");

                // random delay 0,5 - 2,5 s
                Thread.Sleep(r.Next(500, 2500));

                //start time of the game
                start = DateTime.Now; // start time

                // wait for players input
                Input($"Estimate {target} s time and push enter!");

                // stop time of the game
                stop = DateTime.Now;

                // calculate the result in seconds
                time = (stop - start).TotalSeconds;
                result = time - target; // difference between target and time

                // write the game results to the console
                Console.WriteLine($"Your estimated time is {time:f2} s and {result:f2} s");

                // send results to the server - format as server needs
                sender.WriteLine($"res: {nickname}, {result:F2}, {target:F2}, {stop.ToString("dd.MM.yyy HH.mm.ss")}");

                // do we want to play again?
                m = Input("Just press enter if you want to play a new game or " +
                    "to quit press another key and enter!");
                if (m != "")
                {
                    play = false;
                    if (m == "stop") // stop message to the server?
                    {
                        sender.WriteLine("stop: stop"); // send it
                        Thread.Sleep(2000);             // and wait 2 seconds
                    }
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
