//==================================================//
//                                                  //
//          ****** Tasks & monitor ******           //
//                                                  //
//              Lassi Laitinen 1801311              //
//        Konstantinos Antonopoulos 1801321         //
//              Tommi Töyrylä 1800413               //
//                                                  //
//==================================================//


using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

namespace tasks_monitor
{
    class Program
    {
        static int[] storage; // cell count as command line argument value
        static Task[] tasks; // = new Task[10];

        static Random r = new Random((int)DateTime.Now.Ticks);
        static object mylock = new object();    // used for locking by Monitor

        static void Main(string[] args)
        {
            // 1. command line args
            Console.WriteLine("args count: " + args.Length);
            if(args.Length != 2)    // we expect two command line args
            {
                Console.WriteLine("invalid amount of args!");
                return; // exit program!
            }

            int storagelen = 0;
            int tasknum = 0;

            if(!int.TryParse(args[0],out storagelen))  // we accept just int input
            {
                Console.WriteLine("argument \"{0}\" is not int", args[0]);
                return; // exit!
            }

            if (!int.TryParse(args[1], out tasknum))
            {
                Console.WriteLine("argument \"{0}\" is not int", args[1]);
                return; // exit!
            }

            // 2. init storage & tasknum
            storage = new int[storagelen];
            //Console.WriteLine("[{0}]", string.Join(", ", storage));

            tasks = new Task[tasknum];

            // 3. create the tasks. 
            for (int i = 0; i < tasks.Length; i++)
            {
                tasks[i] = Task.Factory.StartNew((object x) => {

                    // convert lambda function input param to int
                    int ix = (int)x;

                    // loop where we r/w storage contents until storage array is full
                    for(; ; )
                    {
                        Monitor.Enter(mylock);  // take the lock

                        // loop to check (up to all) cells to find empty cell
                        bool foundEmptyCell = false;
                        for (int j = 0; j < storage.Length; j++)
                        {
                            if (storage[j] == 0)   // found an empty cell
                            {
                                foundEmptyCell = true;
                                storage[j] = ix;   // fill it with my id
                                break;
                            }
                        }

                        Monitor.Exit(mylock);   // release the lock
                        if (!foundEmptyCell)    // storage is full?
                            break;
                        // a short rest after producing one product
                        Thread.Sleep(r.Next(10,101));
                    }
                }, 

                i + 1); // i+1 is the input param for the lambda

            }

            // 4. wait until the tasks end
            Task.WaitAll(tasks);
            Console.WriteLine("[{0}]", string.Join(", ", storage));

            Console.WriteLine();

            // List for occurences
            List<int> occ = new List<int>();

            int temp = 0; // Temporary variable for counting
            int count = 0; // Counted variables

            Console.WriteLine("Task | Occurence");

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
                    Console.WriteLine(storage[i] + "    | " + temp);
                }
                if (count >= storage.Length)
                {
                    break;
                }

            }

        }
    }
}
