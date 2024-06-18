using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace WinFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {

            InitializeComponent();
        }

        private void textBox1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        public static int ProgressbarSet(int max)
        {
            return max;
        }

        public static int ProgressbarAdd(int v)
        {
            return v;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Affine ciper = new Affine(int.Parse(textBox5.Text), textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text);
            ciper.Encrypt();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Affine ciper = new Affine(int.Parse(textBox5.Text), textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text);
            ciper.LoadKeys(textBox3.Text, textBox4.Text);
            ciper.Decrypt();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
