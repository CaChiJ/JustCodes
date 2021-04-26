using System;

namespace MainApp.cs
{
    class Program
    {
        static void Main(string[] args)
        {
            sbyte a = -10;
            // sbyte a = -500000000000; <- ERROR
            byte b = 40;

            Console.WriteLine("a={0}, b={1}", a, b);

            short c = -30000;
            ushort d = 60000;

            Console.WriteLine("c={0}, d={1}", c, d);

            int e = -10000000;
            uint f = 300000000;

            Console.WriteLine("e={0}, f={1}", e, f);

            long g = -500000000000;
            ulong h = 2000000000000000000;

            Console.WriteLine("g={0}, h={1}", g, h);
        }
    }
}
