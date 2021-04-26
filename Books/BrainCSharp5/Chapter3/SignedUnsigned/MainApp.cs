using System;

namespace SignedUnsigned
{
    class MainApp
    {
        static void Main(string[] args)
        {
            byte a = 255;   //2진수 1111 1111 대입
            sbyte b = (sbyte)a;

            Console.WriteLine(a);   // 255
            Console.WriteLine(b);   // -1
        }
    }
}
