namespace Baby_Algorithms
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 1;
            int b = 2;
            Console.WriteLine($"Calculation 1: a + b = {a + b}\nCalculation 2: b - a = {b - a}\nCalculation 3: a / b = {a / b}\nCalculation 4: a * b = {a * b}");
            
            Console.Write("Please input the diameter of the sphere: ");
            const float PI = 3.1415926535897931f;
            try { float sphereDiameter = float.Parse(Console.ReadLine()!); }
            catch 
            { 
                Console.Write("Please input the diameter of the sphere: ");
                float sphereDiameter = float.Parse(Console.ReadLine()!);
            }
            float sphereRadius = sphereDiameter / 2;
            float area = 4*PI*(sphereRadius*sphereRadius);  //A=4PIRsqrd
            Console.WriteLine($"The area of the sphere is: {area}");

        }
    }
}
