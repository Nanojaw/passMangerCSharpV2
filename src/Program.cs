using System;

namespace passMangerCSharpV2 // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            if (File.Exists("theFileOfDoom.txt")) {
                application.run(true);
            }
            else {
                application.run(false);
            }
        }
    }
}
