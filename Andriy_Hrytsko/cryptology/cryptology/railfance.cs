using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Windows.Input;
using static System.Net.Mime.MediaTypeNames;



namespace cryptology
{
    public partial class railfance : Form
    {
        public railfance()
        {
            InitializeComponent();
        }

        public string EncryptAsync(string decrData, int key)
        {
            if (key <= 1)
                return decrData;

            var decrDataLength = decrData.Length;
            var decrVector = new int[decrDataLength];
            var delta = 1;
            var charPositionInEncryptedString = 0;

            for (var i = 0; i < decrDataLength; i++)
            {
                if (charPositionInEncryptedString > key - 2 || (charPositionInEncryptedString <= 0 && delta < 0))
                    delta = -delta;

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

            var result = new StringBuilder();
            for (var i = res.Length - 1; i >= 0; i--)
                result.Append(res[i]);

            return result.ToString();
        }

        public static string Decryption(string cipher_text, int key, int block_size = 1000)
        {
            char[,] array = new char[key, cipher_text.Length];
            int row = 0;
            int col = 0;
            bool direction = false;

            for (int i = 0; i < cipher_text.Length; i++)
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
                for (int j = 0; j < cipher_text.Length; j++)
                    if (array[i, j] == '*')
                    {
                        array[i, j] = cipher_text[index];
                        index++;
                    }


            string encrypted_text = "";
            row = 0; col = 0;
            for (int i = 0; i < cipher_text.Length; i++)
            {
                if (row == 0)
                    direction = true;
                if (row == key - 1)
                    direction = false;

                if (cipher_text[i] != '*')
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
    

        private async void button3_Click(object sender, EventArgs e)
        {
            string filePath = textBox1.Text;
            int chunkSize = 1000;
            try
            {
                string text = await ReadTextFromFileAsync(filePath);
                List<string> chunks = new List<string>();

                int key = int.Parse(textBox4.Text);

                var startTime = DateTime.Now;

                for (int i = 0; i < text.Length; i += chunkSize)
                {
                    int length = Math.Min(chunkSize, text.Length - i);
                    string chunk = text.Substring(i, length);
                    chunks.Add(chunk);
                }

                string[] chunksArray = chunks.ToArray();

                Parallel.ForEach(chunksArray, (chunk, state, index) =>
                {
                    chunksArray[index] = EncryptAsync(chunk,key);
                });

                string encryptedText = string.Join("", chunksArray);

                string outputPath = textBox2.Text;

                await WriteTextToFileAsync(outputPath, encryptedText);

                for (int i = 0; i < encryptedText.Length; i += chunkSize)
                {
                    int length = Math.Min(chunkSize, encryptedText.Length - i);
                    string chunk = encryptedText.Substring(i, length);
                    chunks.Add(chunk);
                }

                string[] chunksArrayD = chunks.ToArray();

                Parallel.ForEach(chunksArrayD, (chunk, state, index) =>
                {
                    chunksArrayD[index] = Decryption(encryptedText, key);
                });

                string decryptedText = string.Join("", chunksArray);

                await WriteTextToFileAsync("D:\\Visual studio\\проекти\\cryptology\\cryptology\\decryption.txt", decryptedText);


                var endTime = DateTime.Now;

                var duration = endTime - startTime;
                timeNeeded.Text = $"Time: {duration.TotalMilliseconds} мс";
                MessageBox.Show("Текст успішно зашифровано та збережено в файл.");


            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: перевірте чи всі дані введено вірно");
            }
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string word = textBox6.Text;
                int key = int.Parse(textBox5.Text);

                var startTime = DateTime.Now;
                string encryptedText = EncryptAsync(word, key);
                encryptedText = encryptedText.Replace(" ", "");

                var endTime = DateTime.Now;
                var duration = endTime - startTime;

                string decryptedText = Decryption(encryptedText, key);

                await WriteTextToFileAsync("D:\\Visual studio\\проекти\\cryptology\\cryptology\\decryption.txt", decryptedText);


                timeNeeded.Text = $"Time: {duration.TotalMilliseconds} мс";
                label8.Text = encryptedText;

            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: перевірте чи всі дані введено вірно");
            }
        }

        public Task<string> ReadTextFromFileAsync(string filePath)
        {
            return Task.Run(() => File.ReadAllText(filePath));
        }

        public Task WriteTextToFileAsync(string filePath, string text)
        {
            return Task.Run(() => File.WriteAllText(filePath, text));
        }
    

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void timeNeeded_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            mainMenu mMR = new mainMenu();
            mMR.ShowDialog();
            this.Close();
        }
    }
}