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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Vigenere vigenere = new Vigenere(textBox1.Text, textBox2.Text, textBox5.Text, int.Parse(textBox3.Text));
            vigenere.Encrypt();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Vigenere vigenere = new Vigenere(textBox1.Text, textBox2.Text, textBox5.Text, int.Parse(textBox3.Text));
            vigenere.Decrypt();
        }
    }
}
