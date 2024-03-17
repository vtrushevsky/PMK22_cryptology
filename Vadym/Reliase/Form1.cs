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
    public partial class Form1 : Form
    {

        public Form1()
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
                Cip.Cipher(Input.Text, output.Text, Key.Text, Block.Text, EncryptData1);
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
        public string EncryptData1(string decrData, int key)
        {
            if (key == 1) return decrData;
            var decrDataLength = decrData.Length;

            var decrVector = new int[decrDataLength];
            var delta = 1;
            var charPositionInEncryptedString = 0;
            for (var i = 0; i < decrDataLength; i++)
            {
                if (charPositionInEncryptedString > key - 2 || (charPositionInEncryptedString <= 0 && delta < 0)) delta = -delta;
                decrVector[i] = charPositionInEncryptedString;
                charPositionInEncryptedString += delta;
            }

            var res = new string[key];
            for (var i = 0; i < decrDataLength; i++)
            {
                for (var j = 0; j < key; j++)
                {
                    if (decrVector[i] == j)
                        res[j] += decrData[i];
                }
            }

            var result = string.Empty;
            for (var i = res.Length - 1; i != -1; i--)
                result += res[i];

            return result;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form2 f2 = new Form2();
            f2.ShowDialog();
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form5 f5 = new Form5();
            f5.ShowDialog();
            this.Close();
        }
    }
}
    

