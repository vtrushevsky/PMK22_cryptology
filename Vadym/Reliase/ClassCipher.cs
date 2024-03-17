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
    public class ClassCipher
    {
        public bool ValidateInput(string inputFileName, string outputFileName, string key, string block)
        {
            if (!File.Exists(inputFileName))
            {
                MessageBox.Show("Input file does not exist.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!File.Exists(outputFileName))
            {
                MessageBox.Show("Output file does not exist.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!int.TryParse(key, out int number) || number <= 0)
            {
                MessageBox.Show("Invalid key value. Key must be a positive integer.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (!int.TryParse(block, out int chunkSize) || chunkSize < 0)
            {
                MessageBox.Show("Invalid block size. Block size must be a positive integer.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            if (string.IsNullOrWhiteSpace(inputFileName) || string.IsNullOrWhiteSpace(outputFileName) || string.IsNullOrWhiteSpace(key) || string.IsNullOrWhiteSpace(block))
            {
                MessageBox.Show("All fields must be filled.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            return true;
        }
        public void Cipher(string inputFileName, string outputFileName,string key,string block, Func<string, int, string> function)
        {
            try
            {



                int number = int.Parse(key);
                int chunkSize = int.Parse(block);
                string input = File.ReadAllText(inputFileName);
                List<string> chunks = new List<string>();
                string result;
               
                if (chunkSize == 0)
                {

                    result = function(input, number);
                }
                else
                {

                    for (int i = 0; i < input.Length; i += chunkSize)
                    {
                        int length = Math.Min(chunkSize, input.Length - i);
                        string chunk = input.Substring(i, length);
                        chunks.Add(chunk);
                    }

                    string[] chunksArray = chunks.ToArray();

                    Parallel.ForEach(chunksArray, (chunk, state, index) =>
                    {
                        chunksArray[index] = function(chunk, number);
                    });

                    result = string.Join("", chunksArray);
                }
                
                File.WriteAllText(outputFileName, result);
                
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
