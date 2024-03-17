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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
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
        static string DecryptData(string encrData, int key)

        {
            if (key == 1) return encrData;

            var encrDataLength = encrData.Length;

            var decrVector = new int[encrDataLength];
            var delta = 1;
            var charPositionInEncryptedString = 0;
            for (var i = 0; i < encrDataLength; i++)
            {
                if (charPositionInEncryptedString > key - 2 || (charPositionInEncryptedString <= 0 && delta < 0)) delta = -delta;
                decrVector[i] = charPositionInEncryptedString;
                charPositionInEncryptedString += delta;
            }

            var res = new StringBuilder[encrDataLength];
            for (var i = 0; i < encrDataLength; i++)
            {
                res[i] = new StringBuilder();
            }

            for (var i = encrDataLength - 1; i >= 0; i--)
            {
                res[decrVector[i]].Append(encrData[i]);
            }

            var result = new StringBuilder();
            for (var i = 0; i < encrDataLength; i++)
            {
                result.Append(res[i]);
            }

            return result.ToString();
        }



        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 f1 = new Form1();
            f1.ShowDialog();
            this.Close();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void Times_Click(object sender, EventArgs e)
        {

        }

        private void Block_TextChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void Key_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void output_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void Input_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
    
}
