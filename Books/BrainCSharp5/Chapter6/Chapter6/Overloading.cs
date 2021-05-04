using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chapter6
{
    class Overloading
    {
        public static int Plus(int a, int b)
        {
            Console.WriteLine("Calling int Plus(int, int)...");
            return a + b;
        }

        public static int Plus(int a, int b, int c)
        {
            Console.WriteLine("Calling int Plus(int,int,int)");
            return a + b + c;
        }

        public static double Plus(double a, double b)
        {
            Console.WriteLine("Calling double Plus(double,double)...");
            return a + b;
        }

        public static double Plus(int a, double b)
        {
            Console.WriteLine("Calling double Plus(int,double)...");
            return a + b;
        }
    }
}
