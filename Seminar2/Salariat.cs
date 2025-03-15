using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace Seminar2
{
    public class Salariat : ICloneable
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

        static public Salariat operator +(Salariat left, Salariat right)
        {
            return new Salariat()
            {
                nume = left.Nume + " "+ right.Nume,
                Salariu_Orar = left.Salariu_Orar + right.Salariu_Orar,
                Numar_Ore = left.Numar_Ore + right.Numar_Ore
            };
        }
      static public bool operator ==(Salariat left, Salariat right)
            {
                return (left.Salariul==right.Salariul);
            }

        static public bool operator !=(Salariat left, Salariat right)
        {
            return (left.Salariul!=right.Salariul);
        }

        static public Salariat operator ++(Salariat sal)
        {
            sal.Numar_Ore++;
            return sal;
        }

        public char this[int k] => nume[k];
        
        public override string ToString() => $"Salariatul {nume} are salariul {Salariul}";

        public object Clone()
        {
            return new Salariat 
            { 
                Nume=this.Nume, 
                Numar_Ore=this.Numar_Ore,
                Salariu_Orar=this.Salariu_Orar 
            };
        }
    }
}
