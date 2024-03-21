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
            string word = wordCesarFast.Text;
            int key = int.Parse(keyCesar.Text);
            string encryptedWord = CaesarEncrypt(word, key);
            cesarEncrWord.Text = encryptedWord;
        }
        private void cesarEncLB_Click(object sender, EventArgs e)
        {
            string filePath = cesarPath.Text;
            string word = File.ReadAllText(filePath);
            int key = int.Parse(keyLEncr.Text);
            string encryptedWord = CaesarEncrypt(word, key);
            string outputPath = cesarDecrPath.Text;
            File.WriteAllText(outputPath, encryptedWord);
        }
        private string CaesarEncrypt(string word, int key)
        {
            var startTime = DateTime.Now;
            StringBuilder encryptedWord = new StringBuilder();
            foreach (char c in word)
            {
                if (char.IsLetter(c))
                {
                    char offset = char.IsUpper(c) ? 'A' : 'a';
                    encryptedWord.Append((char)((c + key - offset) % 26 + offset));
                }
                else
                {
                    encryptedWord.Append(c);
                }
            }

            var endTime = DateTime.Now;

            var duration = endTime - startTime;
            timeNeededC.Text = $"Time: {duration.TotalMilliseconds} мс";
            return encryptedWord.ToString();

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

        private void backToMenuCesar_Click(object sender, EventArgs e)
        {
            this.Hide();
            mainMenu mM = new mainMenu();
            mM.ShowDialog();
            this.Close();
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


    }
}
