using System;
using Libraries;

namespace factorial
{
    public class Program
    {

        static void Main(string[] args)
        {
            for (int i = 1; i < 11; i++)
            {
                Console.WriteLine(Factorial.Compute(i));
            }
        }
    }
}
