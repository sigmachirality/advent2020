using System;
using System.Collections.Generic;

namespace day3
{
    class Program
    {
        static void Main(string[] args)
        {
            // Read in lines
            String line;
            List<String> lines = new List<String>();
            System.IO.StreamReader file = new System.IO.StreamReader("./day3.txt");  
            while((line = file.ReadLine()) != null)  
            {  
                lines.Add(line);
                Console.WriteLine(line);
            }

            // Part 1
            long count = 0;
            for (int x = 0; x < lines.Count; x++) {
                int y = x * 3;
                if (lines[x][y % lines[0].Length] == '#') {
                    count++;
                }
            }
            Console.WriteLine(count);

        }
    }
}
