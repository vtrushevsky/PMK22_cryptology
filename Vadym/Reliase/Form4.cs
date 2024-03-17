using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Reliase
{
    public partial class Form4 : Form
    {

        public Form4()
        {
            InitializeComponent();
        }


        public void button1_Click(object sender, EventArgs e)
        {



            Stopwatch stopwatch = new Stopwatch();

            ClassCipher Cip = new ClassCipher();
            if (Cip.ValidateInput(Input.Text, output.Text, Key.Text, Block.Text))
            {
                stopwatch.Start();
                Cip.Cipher(Input.Text, output.Text, Key.Text, Block.Text, DecryptData);
                stopwatch.Stop();
                string time1 = $"{stopwatch.Elapsed}";
                Times.Text = time1;
                ShowSuccessMessage("encryption is correctly ");
            }
            else
            {
                return;
            }


        }

        static void ShowSuccessMessage(string message)
        {
            MessageBox.Show(message, "success", MessageBoxButtons.OK, MessageBoxIcon.Information);

        }
        public static char cipher(char ch, int key)
        {
            if (!char.IsLetter(ch))
            {

                return ch;
            }

            char d = char.IsUpper(ch) ? 'A' : 'a';
            return (char)((((ch + key) - d) % 26) + d);


        }


        public static string EncryptData(string input, int key)
        {
            string output = string.Empty;

            foreach (char ch in input)
                output += cipher(ch, key);

            return output;
        }
        public static string DecryptData(string input, int key)
        {
            return EncryptData(input, 26 - key);
        }

        

        private void button2_Click_1(object sender, EventArgs e)
        {
            this.Hide();
            Form3 f3 = new Form3();
            f3.ShowDialog();
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form7 f7 = new Form7();
            f7.ShowDialog();
            this.Close();
        }
    }
}
