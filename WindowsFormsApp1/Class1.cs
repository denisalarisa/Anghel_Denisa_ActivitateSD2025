using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Schema;

namespace WindowsFormsApp1
{
    class ExArgument0 : Exception
    {
        public ExArgument0() : base("Coeficient invalid");
        
    }

    
    internal class Class1
    {
        int coef1, coef2, coefL;
        float RAD1, RAD2, delta;

        public Class1() {

            coef1 = 1;
            coef2 = coefL = 0;
        }

        public int Cx2()
        {
            get{
                return coef1;
            }

            set{
                if (value !=0)
                    coef1=value;
                else
                    throw new ExArgument0();

            }
        }

        public int Cx1
        {
            get => coef1;
            set => coef1=value;
        }

        void CalculDelta()
        {
            this.delta=coef2*coef2 - 4 * coefL * coef1;
            if (delta==0)
            {

            }
        }
    }
    
    

}
