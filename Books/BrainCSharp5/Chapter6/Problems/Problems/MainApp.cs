using System;
using System.Diagnostics;

namespace Problems
{
    class MainApp
    {
        static void Main(string[] args)
        {
            #region test Problem1
            Console.Write("test Problem1.cs ...");

            Debug.Assert(Problem1.Square(3) == 9);
            Debug.Assert(Problem1.Square(34.2) == 1169.64);

            Console.WriteLine("OK");
            #endregion


            #region Problem2
            Console.Write("test Problem2.cs ... ");

            double result;
            Problem2.Mean(out result, 1, 2, 3, 4, 5);
            Debug.Assert(result == 3);

            Problem2.Mean(out result, 1.5, 2.3, 3, 3.7, 4.5);
            Debug.Assert(result == 3);

            Console.WriteLine("OK");
            #endregion


            #region Problem3
            Console.Write("test Problem3.cs ... ");

            int c1;
            Problem3.Plus(3, 4, out c1);
            Debug.Assert(c1 == 7);
            double c2;
            Problem3.Plus(2.4, 3.1, out c2);
            Debug.Assert(c2 == 5.5);

            Console.WriteLine("OK");
            #endregion
        }
    }
}
