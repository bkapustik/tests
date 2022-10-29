using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Libraries;

namespace factorial
{
    public class Program
    {
        static void Main(string[] args)
        {
            for (int i = 1; i < 11; i++)
            {
                Console.Write(Factorial.Compute(i));
                Console.Write(" ");
            }
        }
    }
}
