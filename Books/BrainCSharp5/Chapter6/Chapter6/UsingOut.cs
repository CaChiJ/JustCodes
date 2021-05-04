using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Chapter6
{
    class UsingOut
    {
        public static void Divide(int a, int b, out int quotient, out int remainder)
        {
            quotient = a / b;
            remainder = a % b;
        }

        static void DivideWithRef(int a, int b, ref int quotient, ref int remainder)
        {
            // 바람직하지 않은 코드
            quotient = a / b;
            remainder = a % b;
        }
    }
}
