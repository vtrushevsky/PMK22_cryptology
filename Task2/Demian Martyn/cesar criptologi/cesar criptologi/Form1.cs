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

namespace cesar_criptologi
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            LangvicForChifer.Items.AddRange(new string[] { "Українська", "Англійська"});
        }

        static async Task<string> ReadFileAsync(string filePath)
        {
            try
            {
                using (StreamReader sr = new StreamReader(filePath))
                {
                    return await sr.ReadToEndAsync();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error reading the file: " + ex.Message);
                return null;
            }
        }

        static async Task WriteTextToFileAsync(string filePath, string text)
        {
            try
            {
                
                using (var stream = new FileStream(filePath, FileMode.Create, FileAccess.Write, FileShare.None, bufferSize: 4096, useAsync: true))
                using (var writer = new StreamWriter(stream))
                {
                    
                    await writer.WriteAsync(text);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error writing to the file: " + ex.Message);
            }
        }

        private async void EncriptingButton_Click(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();
            CaesarCipher caesarCipher = new CaesarCipher();

            stopwatch.Start();

            string text = await ReadFileAsync(LincReadFile.Text);

            int numberOfCores = Environment.ProcessorCount;

            int chunkSize = text.Length / numberOfCores;
            string[] chunks = new string[numberOfCores];
            for (int i = 0; i < numberOfCores; i++)
            {
                chunks[i] = text.Substring(i * chunkSize, (i == numberOfCores - 1) ? text.Length - i * chunkSize : chunkSize);
            }

            string[] encryptedChunks = new string[numberOfCores];

            await Task.Run(() =>
            {
                Parallel.For(0, numberOfCores, i =>
                {
                    encryptedChunks[i] = caesarCipher.Encrypt(chunks[i], (int)KeyForChifer.Value, (string)LangvicForChifer.SelectedItem);
                });
            });

            string encryptedText = string.Join("", encryptedChunks);

            await WriteTextToFileAsync(LincWrietFile.Text, encryptedText);
            stopwatch.Stop();
            TameDoing.Text = $"{stopwatch.Elapsed.ToString()}";
        }

        private async void DecriptingBatton_Click(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();
            CaesarCipher caesarCipher = new CaesarCipher();

            stopwatch.Start();

            string text = await ReadFileAsync(LincReadFile.Text);

            int numberOfCores = Environment.ProcessorCount;

            int chunkSize = text.Length / numberOfCores;
            string[] chunks = new string[numberOfCores];
            for (int i = 0; i < numberOfCores; i++)
            {
                chunks[i] = text.Substring(i * chunkSize, (i == numberOfCores - 1) ? text.Length - i * chunkSize : chunkSize);
            }

            string[] encryptedChunks = new string[numberOfCores];

            await Task.Run(() =>
            {
                Parallel.For(0, numberOfCores, i =>
                {
                    encryptedChunks[i] = caesarCipher.Decrypt(chunks[i], (int)KeyForChifer.Value, (string)LangvicForChifer.SelectedItem);
                });
            });

            string encryptedText = string.Join("", encryptedChunks);

            await WriteTextToFileAsync(LincWrietFile.Text, encryptedText);
            stopwatch.Stop();
            TameDoing.Text = $"{stopwatch.Elapsed.ToString()}";
        }

    }

    class CaesarCipher
    {
        
        public string Encrypt(string text, int key,string lengvic)
        {
            string result = "";
            int n = 0;
            if(lengvic == "Українська")
            {
                n = 33;
            }
            else if(lengvic == "Англійська")
            {
                n = 26;
            }
    
            foreach (char ch in text)
            {
                if (char.IsLetter(ch))
                {
                    char offset = '0';
                    if (lengvic == "Українська")
                    {
                        offset = char.IsUpper(ch) ? 'А' : 'а';
                    }
                    else if (lengvic == "Англійська")
                    {
                        offset = char.IsUpper(ch) ? 'A' : 'a';
                    }
                    result += (char)((ch + key - offset) % n + offset);
                }
                else
                {
                    result += ch;
                }
            }
            return result;
        }

        
        public string Decrypt(string text, int shift, string lengvic)
        {
            int n = 0;
            if (lengvic == "Українська")
            {
                n = 33;
            }
            else if (lengvic == "Англійська")
            {
                n = 26;
            }
            return Encrypt(text, n - shift, lengvic);
        }
    }




}
