using CipherRailFence;
using Cryptology;
using System.Diagnostics;

namespace WinFormsApp1
{
    public partial class RailFence : Form
    {

        public RailFence()
        {
            InitializeComponent();

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void ButtonEcrypted(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();

            stopwatch.Start();
            string file_path_not_enrypted = textBox1.Text;
            string str_key = textBox2.Text;
            string block_size_str = textBox14.Text;
            int block_size = Convert.ToInt32(block_size_str);

            if (int.TryParse(str_key, out int key))
            {
                string file_path_to_enrypted = textBox3.Text;
                string txt_from_file = FilesFunction.ReadTextFile(file_path_not_enrypted);
                string encrypted_file = CipherRailFenceClass.Encrypted(txt_from_file, key, block_size);
                FilesFunction.WriteToFile(file_path_to_enrypted, encrypted_file);
            }

            stopwatch.Stop();
            long elapsedMilliseconds = stopwatch.ElapsedMilliseconds;
            label10.Text = $"Execution time: {elapsedMilliseconds} ms";
        }


        private void ButtonDecrypted(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            string file_path_enrypted = textBox5.Text;
            string str_key = textBox6.Text;
            string block_size_str = textBox14.Text;
            int block_size = Convert.ToInt32(block_size_str);

            if (int.TryParse(str_key, out int key))
            {
                string file_path_to_decrypted = textBox4.Text;

                string txt_from_file = FilesFunction.ReadTextFile(file_path_enrypted);

                string decrypted_file = CipherRailFenceClass.Decrypted(txt_from_file, key, block_size);
                FilesFunction.WriteToFile(file_path_to_decrypted, decrypted_file);
            }

            stopwatch.Stop();
            long elapsedMilliseconds = stopwatch.ElapsedMilliseconds;
            label10.Text = $"Execution time: {elapsedMilliseconds} ms";
        }

        private void ButtonEn(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();

            stopwatch.Start();

            string word = textBox7.Text;
            string str_key = textBox8.Text;
            string block_size_str = textBox14.Text;
            int block_size = Convert.ToInt32(block_size_str);

            if (int.TryParse(str_key, out int key))
            {
                string encrypted_word = CipherRailFenceClass.Encrypted(word, key, block_size);
                label1.Text = $"Encrypted: {encrypted_word}";
            }

            stopwatch.Stop();
            long elapsedMilliseconds = stopwatch.ElapsedMilliseconds;
            label10.Text = $"Execution time: {elapsedMilliseconds} ms";
        }

        private void ButtonDe(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();

            stopwatch.Start();

            string word = textBox10.Text;
            string str_key = textBox9.Text;
            string block_size_str = textBox14.Text;
            int block_size = Convert.ToInt32(block_size_str);

            if (int.TryParse(str_key, out int key))
            {
                string decrypted_word = CipherRailFenceClass.Decrypted(word, key, block_size);

                label2.Text = $"Decrypted: {decrypted_word}";
            }

            stopwatch.Stop();
            long elapsedMilliseconds = stopwatch.ElapsedMilliseconds;
            label10.Text = $"Execution time: {elapsedMilliseconds} ms";
        }

        private void button4_Click(object sender, EventArgs e)
        {

            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            string word = textBox11.Text;
            string decrypte = CipherRailFenceClass.DecryptWithoutKey(word);
            label7.Text = $"Decrypted: {decrypte}";

            stopwatch.Stop();
            long elapsedMilliseconds = stopwatch.ElapsedMilliseconds;
            label10.Text = $"Execution time: {elapsedMilliseconds} ms";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();
            string file_path_enrypted = textBox12.Text;

            string file_path_to_decrypted = textBox13.Text;

            //string result = CipherRailFenceClass.DecryptFileWithoutKey(file_path_enrypted, file_path_to_decrypted);
            //label9.Text = $"Status: {result}";

            stopwatch.Stop();
            long elapsedMilliseconds = stopwatch.ElapsedMilliseconds;
            label10.Text = $"Execution time: {elapsedMilliseconds} ms";

        }

 
    }
}