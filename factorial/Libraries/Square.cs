using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Libraries
{
    public class Square
    {
        public static void PrintSquares(int number)
        {
            for (int i = 1; i < number + 1; i++)
            Console.WriteLine(i*i);         
        }
    }
}
