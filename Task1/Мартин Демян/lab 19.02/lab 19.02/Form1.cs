using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;

namespace lab_19._02
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (Convert.ToInt32(numericUpDown1.Value) >= 2)
            {
                Stopwatch stopwatch = new Stopwatch();
                string text = Form1.ReadFail(textBox1.Text);
                stopwatch.Start();


                Criptologi criptologi = new Criptologi();

                int numberOfCores = Environment.ProcessorCount;
                label3.Text = Convert.ToString(  numberOfCores);

                int chunkSize = text.Length / numberOfCores;
                string[] chunks = new string[numberOfCores];
                for (int i = 0; i < numberOfCores; i++)
                {
                    chunks[i] = text.Substring(i * chunkSize, (i == numberOfCores - 1) ? text.Length - i * chunkSize : chunkSize);
                }

                string[] encryptedChunks = new string[numberOfCores];


                Parallel.For(0, numberOfCores, i =>
                {
                    encryptedChunks[i] = criptologi.Encryption(chunks[i], (int)numericUpDown1.Value);
                });

                string encryptedText = string.Join("", encryptedChunks);

                stopwatch.Stop();

                Resout resout = new Resout();
                if (checkBox1.Checked == true)
                {
                    Form1.WriteFail(textBox2.Text, encryptedText);
                }
                else
                {
                    resout.TXT = encryptedText;
                }
                
                resout.Time = stopwatch.Elapsed.ToString();
                this.Hide();
                resout.Show();


            }
            else
            {
                label3.Text = "У вас неправильний ключ \n Для ефективного шифрування він має бути >+2";
            }
        }

        static string ReadFail(string nameFail)
        {

            String Resout = "";
            String line;
            try
            {
                StreamReader sr = new StreamReader(nameFail);
                line = sr.ReadLine();
                while (line != null)
                {
                    Resout += line;
                    line = sr.ReadLine();
                }
                sr.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
            return Resout;
        }

        static void WriteFail(string nameF, string txt)
        {
            try
            {
               
                StreamWriter sw = new StreamWriter(nameF);
                
                sw.WriteLine(txt);
                
                sw.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
            finally
            {
                Console.WriteLine("Executing finally block.");
            }
        }

        

        private void button2_Click(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();
            string text = Form1.ReadFail(textBox1.Text);
            stopwatch.Start();


            Criptologi criptologi = new Criptologi();
            int numberOfCores = Environment.ProcessorCount;

            int chunkSize = text.Length / numberOfCores;
            string[] chunks = new string[numberOfCores];
            for (int i = 0; i < numberOfCores; i++)
            {
                chunks[i] = text.Substring(i * chunkSize, (i == numberOfCores - 1) ? text.Length - i * chunkSize : chunkSize);
            }

            string[] encryptedChunks = new string[numberOfCores];


            Parallel.For(0, numberOfCores, i =>
            {
                encryptedChunks[i] = criptologi.Decryption(chunks[i], (int)numericUpDown1.Value);
            });

            string encryptedText = string.Join("", encryptedChunks);

            stopwatch.Stop();

            Resout resout = new Resout();
            if (checkBox1.Checked == true)
            {
                Form1.WriteFail(textBox2.Text, encryptedText);
            }
            else
            {
                resout.TXT = encryptedText;
            }

            resout.Time = stopwatch.Elapsed.ToString();
            this.Hide();
            resout.Show();

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }
    }

    class Criptologi
    {
        public string Encryption(string decrData, int key)
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

        public string Decryption(string encrData, int key)
        {
            char[,] array = new char[key, encrData.Length];
            int row = 0;
            int col = 0;
            bool direction = false;

            for (int i = 0; i < encrData.Length; i++)
            {
                if (row == key - 1 || row == 0)
                    direction = !direction;
                array[row, col] = '*';

                if (direction)
                    row++;

                else
                    row--;
                col++;
            }

            int index = 0;
            for (int i = key - 1; i >= 0; i--)
                for (int j = 0; j < encrData.Length; j++)
                    if (array[i, j] == '*' && index < encrData.Length)
                    {
                        array[i, j] = encrData[index];
                        index++;
                    }


            string encrypted_text = "";
            row = 0; col = 0;
            for (int i = 0; i < encrData.Length; i++)
            {
                if (row == 0)
                    direction = true;
                if (row == key - 1)
                    direction = false;

                if (encrData[i] != '*')
                {
                    encrypted_text += array[row, col++];
                }

                if (direction)
                    row++;
                else
                    row--;
            }
            return encrypted_text;
        }
    }
}
