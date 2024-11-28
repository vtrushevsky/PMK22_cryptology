using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Ceasar ceasar = new Ceasar(textBox1.Text, textBox2.Text, int.Parse(textBox5.Text), int.Parse(textBox3.Text));
            ceasar.Encrypt();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Ceasar ceasar = new Ceasar(textBox1.Text, textBox2.Text, int.Parse(textBox5.Text), int.Parse(textBox3.Text));
            ceasar.Decrypt();
        }
    }
}
