using System;

namespace OverflowUnderflow
{
    class MainApp
    {
        static void Main(string[] args)
        {
            uint a = uint.MaxValue;
            int b = int.MaxValue;

            Console.WriteLine("a = {0, -15} | b = {1, -15}", a, b);

            a = a + 1;  // overflow
            b = b + 1;  // overflow

            Console.WriteLine("a = {0, -15} | b = {1, -15}", a, b);

            a = uint.MinValue;
            b = int.MinValue;

            Console.WriteLine("a = {0, -15} | b = {1, -15}", a, b);

            a = a - 1;  // underflow
            b = b - 1;  // underflow

            Console.WriteLine("a = {0, -15} | b = {1, -15}", a, b);
        }
    }
}
