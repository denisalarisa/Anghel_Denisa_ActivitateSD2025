using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Seminar2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Salariat srez = new Salariat(),
                sal1 = new Salariat() { Nume= "Andrei", Salariu_Orar=80, Numar_Ore=120 },
                sal2 = new Salariat() { Nume="Cosmin", Salariu_Orar = 120, Numar_Ore=80 };

            Console.WriteLine(sal1+"\n"+sal2+"\n");

            srez += sal1;
            Console.WriteLine(srez + "\n");

            
            Console.WriteLine(sal1==sal2);

            Salariat sal3 = sal1.Clone() as Salariat;
            Console.WriteLine(sal3 + "\n" + sal1 +"\n");

            sal3.Nume="Bogdan";
            Console.WriteLine(sal3 + "\n" + sal1 +"\n");

            sal3++;
            Console.WriteLine(sal3 + "\n" + sal1 +"\n");
           
            try
            {
                char c = sal3[100];
                Console.WriteLine(c);
            }

            catch (IndexOutOfRangeException)
            {
                Console.WriteLine("index in afara");
            }

            //exceptie generala
            catch(Exception ex) {
                Console.WriteLine(ex.Message);
            }


            GC.Collect();//face scanarea si vede daca exista corespondenta->elibereaza spatiul


        }
    }
}
