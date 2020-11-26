using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace formCsharp
{
    class zlomek
    {
        private int m_intCitatel;
        private int m_intJmenovatel;

        //konstruktory
        public zlomek()
        {
            m_intJmenovatel = 1;
            m_intCitatel = 0;
        }

        public zlomek(int c, int j)
        {
            m_intCitatel = c;
            m_intJmenovatel = j;
        }
        //metody 

        public int Jmenovatel
        {
            get
            {
                return m_intJmenovatel;
            }
        }

        public int Citatel
        {
            get
            {
                return m_intCitatel;
            }
        }

        public zlomek secti(ref zlomek arg){
            zlomek vysledek = new zlomek();
            vysledek.m_intJmenovatel = m_intJmenovatel * arg.m_intJmenovatel;
            vysledek.m_intCitatel = m_intCitatel * arg.m_intJmenovatel + 
                arg.m_intCitatel * m_intJmenovatel;
            return vysledek;
        }
    }
}
