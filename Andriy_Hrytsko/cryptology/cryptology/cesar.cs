using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace cryptology
{


    public partial class cesar : Form
    {
        public cesar()
        {
            InitializeComponent();
        }

        private void cesarEncrFB_Click(object sender, EventArgs e)
        {
            try
            {
                var startTime = DateTime.Now;

                string word = wordCesarFast.Text;

                if (!int.TryParse(keyCesar.Text, out int key))
                {
                    throw new Exception("The key should be a number.");
                }

                string encryptedWord = Encipher(word, key);
                cesarEncrWord.Text = encryptedWord;

                var endTime = DateTime.Now;
                var duration = endTime - startTime;
                timeNeededC.Text = $"Time: {duration.TotalMilliseconds} мс";
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }
        }
        private void cesarEncLB_Click(object sender, EventArgs e)
        {
            try
            {
                var startTime = DateTime.Now;

                string filePath = cesarPath.Text;
                string lengthB = lengthBox.Text;

                if (!int.TryParse(keyLEncr.Text, out int key))
                {
                    throw new Exception("The key should be a number.");
                }

                string outputPath = cesarEncrPath.Text;

                cipher chikiBriki = new cipher();
                chikiBriki.cipLog(key, lengthB, filePath, outputPath, Encipher);
                string outputPathDe = "C:\\Users\\WellDone\\Source\\Repos\\PMK22_cryptology\\Andriy_Hrytsko\\cryptology\\cryptology\\decryption.txt";

                chikiBriki.cipLog(key, lengthB, outputPath, outputPathDe, Decipher);

                var endTime = DateTime.Now;
                var duration = endTime - startTime;
                timeNeededC.Text = $"Time: {duration.TotalMilliseconds} мс";

                MessageBox.Show("Successfully encrypted");
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }

        }

        public static char cesarCipher(char ch, int key)
        {
            if (!char.IsLetter(ch))
            {
                return ch;
            }

            char d = char.IsUpper(ch) ? 'A' : 'a';
            return (char)((((ch + key) - d) % 26) + d);
        }

        public static string Encipher(string input, int key)
        {
            string output = string.Empty;

            foreach (char ch in input)
                output += cesarCipher(ch, key);

            return output;
        }

        public static string Decipher(string input, int key)
        {
            return Encipher(input, 26 - key);
        }

        public static string FrequencyAnalysis(string input)
        {
            string[] dictionary = File.ReadAllLines(@"C:\Users\WellDone\Source\Repos\PMK22_cryptology\Andriy_Hrytsko\cryptology\cryptology\english_words1.txt");
            string decrypted_word = "this word doesnt exist";

            for (int i = 1; i < input.Length; i++)
            {
                Console.WriteLine($"{i}");
                string maybe_decrypt = Decipher(input, i);

                if (dictionary.Contains(maybe_decrypt))
                    decrypted_word = maybe_decrypt;
            }
            return decrypted_word;

        }

        private void noKeyEncr_Click(object sender, EventArgs e)
        {
            try
            {
                var startTime = DateTime.Now;

                string word = boxWordNoKey.Text;
                if (!word.All(c => char.IsLetter(c) || c == ' '))
                {
                    throw new Exception("The word should only contain letters.");
                }

                string decryptedWord = FrequencyAnalysis(word);

                noKeyWord.Text = decryptedWord;

                var endTime = DateTime.Now;
                var duration = endTime - startTime;
                timeNeededC.Text = $"Time: {duration.TotalMilliseconds} мс";
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }
        }

        private void backToMenuCesar_Click(object sender, EventArgs e)
        {
            this.Hide();
            mainMenu mM = new mainMenu();
            mM.ShowDialog();
            this.Close();
        }
        private void keyCesar_TextChanged(object sender, EventArgs e)
        {

        }

        private void wordCesarFast_TextChanged(object sender, EventArgs e)
        {

        }
        private void cesarEncrWord_Click(object sender, EventArgs e)
        {

        }

        

        private void timeNeededC_Click(object sender, EventArgs e)
        {

        }

        private void cesarPath_TextChanged(object sender, EventArgs e)
        {

        }

        private void cesarDecrPath_TextChanged(object sender, EventArgs e)
        {

        }

        private void keyLEncr_TextChanged(object sender, EventArgs e)
        {

        }

        

        private void boxWordNoKey_TextChanged(object sender, EventArgs e)
        {

        }

        private void noKeyWord_Click(object sender, EventArgs e)
        {

        }

        private void lengthBox_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
