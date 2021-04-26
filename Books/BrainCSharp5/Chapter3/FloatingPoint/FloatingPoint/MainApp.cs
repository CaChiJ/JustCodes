using System;

namespace FloatAndDecimal
{
    class MainApp
    {
        static void Main(string[] args)
        {
            float a = 3.141592653589793238462643383279f;
            Console.WriteLine(a);

            double b = 3.141592653589793238462643383279;
            Console.WriteLine(b);

            decimal c = 3.141592653589793238462643383279m;
            Console.WriteLine(c);
        }
    }
}
