using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C1_demo
{
    //clase
    class Salariat
    {
        string nume;
        int no, so;

        public Salariat() { nume = "Anonim"; no= 0; so = 1; }

        // propietatea este o combinatie intre atribut si metoda;
        public string Nume
        {
            get { return nume; }
            set { nume = value; }
        }
        public int Numar_Ore
        {
            get => no;
            set => no = value;
        }

        public int Salariu_Orar
        {
            get => so;
            set => so = value;
        }

        public int Salariul => no* so;

        public override string ToString() => $"Salariatul {nume} are salariul {Salariul}";


    }


    //altele
    class Program
    {

        static void Main(string[] args)
        {
            Salariat obs = new Salariat();
            Console.WriteLine(obs.ToString());
            Salariat obs1 = new Salariat() { Nume = "Vasile", Numar_Ore =32, Salariu_Orar=15 };
            Console.WriteLine(obs1.ToString());
        }
        
        //    //delegate int del_fopa(int x, int y);


        //    // la out nu trebuie sa i dam o valoare initiala variabilei transmisa prin refereinta;
        //    //static void aduna(int a, int b, out int rez)
        //    //    { rez= a + b; }

        //    //static int aduna(params int[] v)
        //    //{
        //    //    int S = 0;
        //    //    foreach (int el in v) S += el;
        //    //    return S;
        //    }

        //    static void Main(string[] args)
        //    {
        //        //int rez = aduna(10,23,45,20);
        //        //Console.WriteLine("Rez op=" + rez);
        //    }

        //    /* static void Main(string[] args)
        //     {
        //         int t = 20, v = 2;
        //         del_fopa vfa = new del_fopa((a, b) => a*b);

        //         vfa += aduna;
        //         //GetInvocationList() -> scoate rand pe rand functiile;
        //         foreach (del_fopa el in vfa.GetInvocationList())
        //             Console.WriteLine("Rez op=" + el(t, v));
        //     //} */

        //static void Main(string[] args)
        //{
        //    int t = 10, v = 2;
        //    Func<int,int,int> vfa = new Func<int, int, int>((a, b) => a*b);

        //    vfa += aduna;
        //    //GetInvocationList() -> scoate rand pe rand functiile;
        //    foreach (Func<int, int, int> el in vfa.GetInvocationList())
        //        Console.WriteLine("Rez op=" + el(t, v));


        //}

        //static void Main(string[] args)
        //{
        //    int  sum; 
        //    string s;
        //    List<int> ve = new List<int>();
        //    Console.Write("Elementul:");
        //    while ((s= Console.ReadLine()) != null) 
        //    {
        //        ve.Add(Int32.Parse(s));
        //        Console.Write("Elementul:");
        //    }

        //    foreach (int el in ve) Console.WriteLine("Elem: " + el)
        //    sum=ve.Sum(x => x>0?x:0);
        //    Console.WriteLine("Suma Elem pozitive: "+sum);
        //    //from->ia toate elementele din lista
        //    var rez = from el in ve where el>0 select el;
        //    Console.WriteLine("Suma Elem pozitive: "+rez.Sum());

        //}


    }
}