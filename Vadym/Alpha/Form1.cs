using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace Alpha
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string inputFileName = Input.Text;
                string outputFileName = output.Text;

                if (!File.Exists(inputFileName))
                {
                    MessageBox.Show("Input file does not exist.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                if (!File.Exists(outputFileName))
                {
                    MessageBox.Show("Output file does not exist.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                if (!int.TryParse(Key.Text, out int number) || number <= 0)
                {
                    MessageBox.Show("Invalid key value. Key must be a positive integer.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                if (!int.TryParse(Block.Text, out int chunkSize) || chunkSize <= 0)
                {
                    MessageBox.Show("Invalid block size. Block size must be a positive integer.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                if (string.IsNullOrWhiteSpace(Input.Text) || string.IsNullOrWhiteSpace(output.Text) || string.IsNullOrWhiteSpace(Key.Text) || string.IsNullOrWhiteSpace(Block.Text))
                {
                    MessageBox.Show("All fields must be filled.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                string input = File.ReadAllText(inputFileName);
                List<string> chunks = new List<string>();
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();

                for (int i = 0; i < input.Length; i += chunkSize)
                {
                    int length = Math.Min(chunkSize, input.Length - i);
                    string chunk = input.Substring(i, length);
                    chunks.Add(chunk);
                }

                string[] chunksArray = chunks.ToArray();

                Parallel.ForEach(chunksArray, (chunk, state, index) =>
                {
                    chunksArray[index] = T1EncryptData(chunk, number);
                });

                string result = string.Join("", chunksArray);

                stopwatch.Stop();
                File.WriteAllText(outputFileName, result);
                string time1 = $"{stopwatch.Elapsed}";
                Times.Text = time1;
                ShowSuccessMessage("encryption is correctly ");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        static void ShowSuccessMessage(string message)
        {
            MessageBox.Show(message, "success", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        static string T1EncryptData(string decrData, int key)
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
    }
}
