using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace cryptology
{
    internal class cipher
    {

        public void cipLog(int key, string blocks, string filePath, string outPath,Func<string, int, string> function)
        {
            int chunkSize = int.Parse(blocks);

            try
            {
                string text = ReadTextFile(filePath);
                List<string> chunks = new List<string>();

                for (int i = 0; i < text.Length; i += chunkSize)
                {
                    int length = Math.Min(chunkSize, text.Length - i);
                    string chunk = text.Substring(i, length);
                    chunks.Add(chunk);
                }

                string[] chunksArray = chunks.ToArray();

                Parallel.ForEach(chunksArray, (chunk, state, index) =>
                {
                    chunksArray[index] = function(chunk, key);
                });

                string encryptedText = string.Join("", chunksArray);

                string outputPath = outPath;

                WriteToFile(outputPath, encryptedText);

            }
            catch (Exception ex)
            {
                MessageBox.Show($"Помилка: перевірте чи всі дані введено вірно");
            }
   
        }


        public static string ReadTextFile(string filePath)
        {
            try
            {
                string content = File.ReadAllText(filePath);
                return content;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error reading file: {ex.Message}");
                return "";
            }
        }

        public static void WriteToFile(string filePath, string data)
        {
            try
            {
                using (StreamWriter writer = new StreamWriter(filePath))
                {
                    writer.Write(data);
                }

                Console.WriteLine($"The data was successfully written to the file {filePath}.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error writing to file: {ex.Message}");
            }
        }
    }
}
