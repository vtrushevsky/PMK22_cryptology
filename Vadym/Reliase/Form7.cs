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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void Times_Click(object sender, EventArgs e)
        {

        }

        public void button1_Click(object sender, EventArgs e)
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





                string encryptedText = File.ReadAllText(inputFileName);
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                string[] result = new string[2];
                result = CeasarHack(encryptedText);
                string result1 = result[0];
                string key1 = result[1];

                stopwatch.Stop();
                File.WriteAllText(outputFileName, result1);
                string time1 = $"{stopwatch.Elapsed}";
                Key1.Text = key1;
                Times.Text = time1;
                ShowSuccessMessage("hacking is correctly ");
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
        public static char cipher(char ch, int key)
        {
            if (!char.IsLetter(ch))
            {

                return ch;
            }

            char d = char.IsUpper(ch) ? 'A' : 'a';
            return (char)((((ch + key) - d) % 26) + d);


        }
        public string[] CeasarHack(string message, string alphabet = "abcdefghijklmnopqrstuvwxyz")
        {
            Dictionary<char, double> engFrequencies = new Dictionary<char, double>() {
       { 'a', 8.1670 }, { 'b', 1.492 }, { 'c', 2.782 }, { 'd', 4.253 },
       { 'e', 12.702 }, { 'f', 2.228 }, { 'g', 2.015 }, { 'h', 6.094 },
       { 'i', 6.9660 }, { 'j', 0.153 }, { 'k', 0.772 }, { 'l', 4.025 },
       { 'm', 2.4060 }, { 'n', 6.749 }, { 'o', 7.507 }, { 'p', 1.929 },
       { 'q', 0.0950 }, { 'r', 5.987 }, { 's', 6.327 }, { 't', 9.056 },
       { 'u', 2.7580 }, { 'v', 0.978 }, { 'w', 2.361 }, { 'x', 0.150 },
       { 'y', 1.9740 }, { 'z', 0.074 }
       };

            Dictionary<char, int> frequencyMap = new Dictionary<char, int>();

            foreach (char letter in alphabet)
            {
                frequencyMap[letter] = 0;
            }

            foreach (char letter in message)
            {
                if (alphabet.Contains(letter))
                {
                    frequencyMap[letter]++;
                }
            }


            char mostFrequentLetter = ' ';
            int maxFrequency = 0;
            foreach (var entry in frequencyMap)
            {
                if (entry.Value > maxFrequency)
                {
                    mostFrequentLetter = entry.Key;
                    maxFrequency = entry.Value;
                }
            }



            List<KeyValuePair<char, double>> sortedFrequencyList = engFrequencies.ToList();
            sortedFrequencyList.Sort((pair1, pair2) => pair1.Value.CompareTo(pair2.Value));
            string filePath = "D:\\MyProgects\\shifer\\shiferrr\\english_words1.txt";
            string[] lines = File.ReadAllLines(filePath);


            while (sortedFrequencyList.Count > 0)
            {
                KeyValuePair<char, double> lastElement = sortedFrequencyList[sortedFrequencyList.Count - 1];
                char lastletter = lastElement.Key;
                int key = alphabet.IndexOf(mostFrequentLetter) - alphabet.IndexOf(lastletter);

                string result = DecryptData( message, key);
                string[] words = result.Split(' ');

                foreach (string word in words)
                {
                    if (lines.Contains(word))
                    {
                        key = 26 + key;
                        string key1 = key.ToString();
                        string[] resultP = { result, key1 };
                        return resultP;
                    }
                }
                sortedFrequencyList.RemoveAt(sortedFrequencyList.Count - 1);


            }
            string[] resultP1 = { "" };
            return resultP1;

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

       

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form4 f4 = new Form4();
            f4.ShowDialog();
            this.Close();
        }
    }
}
