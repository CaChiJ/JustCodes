using System;

namespace Chapter6
{
    class MainApp
    {
        static void Main(string[] args)
        {
            #region test UsingOut.cs
            printTestTarget("test UsingOut");
            int a = 20;
            int b = 3;
            int c;
            int d;

            UsingOut.Divide(a, b, out c, out d);
            // ERROR : UsingOut.DivideWithRef(a, b, ref c, ref d);

            Console.WriteLine($"a:{a}, b:{b}, a/b:{c}, a%c:{d}", a, b, c, d);
            #endregion


            #region test Overloading.cs
            printTestTarget("Overloading.cs");
            Console.WriteLine(Overloading.Plus(1, 2));
            Console.WriteLine(Overloading.Plus(1, 2, 3));
            Console.WriteLine(Overloading.Plus(1.5, 2.3));
            Console.WriteLine(Overloading.Plus(1, 2.3));
            #endregion


            #region test UsingParams.cs
            printTestTarget("UsingParams.cs");
            Console.WriteLine(UsingParams.Sum(1, 2, 39, 4, 5, 6));
            #endregion
        }

        static void printTestTarget(string testTarget)
        {
            Console.WriteLine("test " + testTarget);
        }
    }
}
