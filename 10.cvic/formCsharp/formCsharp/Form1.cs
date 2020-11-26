using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace formCsharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
            //stisknuti tlacitka
        {
            zlomek z1, z2, vysledek;

            z1 = new zlomek(Int32.Parse(textBox1.Text),Int32.Parse(textBox2.Text));
            z2 = new zlomek(Int32.Parse(textBox4.Text), Int32.Parse(textBox3.Text));

            vysledek = z1.secti(ref z2);

            textBox6.Text = vysledek.Citatel.ToString();
            textBox5.Text = vysledek.Jmenovatel.ToString();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
