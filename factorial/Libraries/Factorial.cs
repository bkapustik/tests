using System;

namespace Libraries
{
    public class Factorial
    {
        public static int Compute(int number)
        {
            for (int i = number - 1; i > 0; i--)
            {
                number *= i;
            }

            return number;
        }
    }
}