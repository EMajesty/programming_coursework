//==================================================//
//                                                  //
//          ****** Threads & mutex ******           //
//                                                  //
//              Lassi Laitinen 1801311              //
//        Konstantinos Antonopoulos 1801321         //
//              Tommi Töyrylä 1800413               //
//                                                  //
//==================================================//


using System;
using System.Collections.Generic;
using System.Threading;

namespace tasks_monitor
{
    class Program
    {
        static int[] storage; // cell count as command line argument value
        static Random r = new Random((int)DateTime.Now.Ticks);
        static Mutex mutex = new Mutex(false); // mutex is not initially owned by anyone

        public static void Main(string[] args)
        {
            // 1. command line args
            Console.WriteLine("args count: " + args.Length);
            if (args.Length != 2)    // we expect two command line args
            {
                Console.WriteLine("invalid amount of args!");
                return; // exit program!
            }

            int threadNum;
            int storagelen = 0;

            if (!int.TryParse(args[0], out storagelen))  // we accept just int input
            {
                Console.WriteLine("argument \"{0}\" is not int", args[0]);
                return; // exit!
            }

            if (!int.TryParse(args[1], out threadNum))
            {
                Console.WriteLine("argument \"{0}\" is not int", args[1]);
                return; // exit!
            }

            // 2. init storage & threadnum
            storage = new int[storagelen];

            Thread[] threads = new Thread[threadNum];


            // Create and name the threads
            for (int i = 0; i < threads.Length; i++)
            {
                threads[i] = new Thread(worker);
                threads[i].Name = i.ToString();
            }

            // Start all threads
            for (int i = 0; i < threads.Length; i++)
            {
                threads[i].Start(); // ths[i].Start(param); ..if worker() is parametrized
            }

            // Let's join to threads
            for (int i = 0; i < threads.Length; i++)
            {
                threads[i].Join();
            }

            Console.WriteLine("[{0}]", string.Join(", ", storage));

            Console.WriteLine();

            // List for occurences
            List<int> occ = new List<int>();

            int temp = 0; // Temporary variable for counting
            int count = 0; // Counted variables

            Console.WriteLine("Thread | Occurence");

            for (int i = 0; i < storage.Length; i++)
            {
                if (!occ.Contains(storage[i]))
                {
                    // Reset temp
                    temp = 0;
                    occ.Add(storage[i]);
                    // Count the occurences
                    for (int j = 0; j < storage.Length; j++)
                    {
                        if (storage[i] == storage[j])
                        {
                            temp++; // Local count
                            count++; // Kind of the global count of elements we have passed
                        }
                    }
                    Console.WriteLine(storage[i] + "      | " + temp);
                }
                if (count >= storage.Length)
                {
                    break;
                }

            }

        }

        public static void worker()
        {
            for (int j = 0; j < storage.Length; j++)
            {
                mutex.WaitOne();
                if (storage[j] == 0)
                {
                    storage[j] = int.Parse(Thread.CurrentThread.Name);
                }
                mutex.ReleaseMutex();
                Thread.Sleep(r.Next(1, 11));
            }
        }
    }
}
