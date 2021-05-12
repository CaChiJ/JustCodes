using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problems
{
    class Problem2
    {
        public static void Mean(out double mean, params double[] args)
        {
            mean = 0;

            foreach (double i in args)
            {
                mean += i;
            }

            mean /= args.Length;
        }
    }
}
