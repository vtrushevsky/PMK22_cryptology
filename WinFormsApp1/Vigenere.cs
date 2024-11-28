using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp1
{
    internal class Vigenere
    {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        public string inputText { get; set; }
        public string outPath { get; set; }
        public string Key { get; set; }
        public int blockSize { get; set; }

        public Vigenere(string input, string output, string key, int blocksize)
        {
            inputText = File.ReadAllText(input);
            outPath = output;
            Key = key.ToLower(); 
            blockSize = blocksize;
        }

        public void Encrypt()
        {
            if (blockSize == 0)
            {
                File.WriteAllText(outPath, EncryptStringWithVigenereCipher(inputText, alphabet, Key));
            }
            else
            {
                int totalBlocks = (inputText.Length + blockSize - 1) / blockSize;
                var blocks = Enumerable.Range(0, totalBlocks)
                                        .AsParallel()
                                        .Select(i => inputText.Substring(i * blockSize, Math.Min(blockSize, inputText.Length - i * blockSize)))
                                        .Select(block => EncryptStringWithVigenereCipher(block, alphabet, Key))
                                        .ToArray();

                File.WriteAllText(outPath, string.Concat(blocks));
            }
        }

        public void Decrypt()
        {
            if (blockSize == 0)
            {
                File.WriteAllText(outPath, DecryptStringWithVigenereCipher(inputText, alphabet, Key));
            }
            else
            {
                int totalBlocks = (inputText.Length + blockSize - 1) / blockSize;
                var blocks = Enumerable.Range(0, totalBlocks)
                                        .AsParallel()
                                        .Select(i => inputText.Substring(i * blockSize, Math.Min(blockSize, inputText.Length - i * blockSize)))
                                        .Select(block => DecryptStringWithVigenereCipher(block, alphabet, Key))
                                        .ToArray();

                File.WriteAllText(outPath, string.Concat(blocks));
            }
        }

        static string EncryptStringWithVigenereCipher(string text, string alphabet, string key)
        {
            StringBuilder encryptedText = new StringBuilder();
            int keyIndex = 0;

            foreach (char c in text)
            {
                if (char.IsLetter(c))
                {
                    int shift = alphabet.IndexOf(char.ToLower(key[keyIndex])) % alphabet.Length;
                    char encryptedChar = ShiftChar(c, alphabet, shift);
                    encryptedText.Append(encryptedChar);
                    keyIndex = (keyIndex + 1) % key.Length;
                }
                else
                {
                    encryptedText.Append(c);
                }
            }

            return encryptedText.ToString();
        }

        static string DecryptStringWithVigenereCipher(string text, string alphabet, string key)
        {
            StringBuilder decryptedText = new StringBuilder();
            int keyIndex = 0;

            foreach (char c in text)
            {
                if (char.IsLetter(c))
                {
                    int shift = alphabet.IndexOf(char.ToLower(key[keyIndex])) % alphabet.Length;
                    char decryptedChar = ShiftChar(c, alphabet, -shift); 
                    decryptedText.Append(decryptedChar);
                    keyIndex = (keyIndex + 1) % key.Length;
                }
                else
                {
                    decryptedText.Append(c);
                }
            }

            return decryptedText.ToString();
        }

        static char ShiftChar(char c, string alphabet, int shift)
        {
            int index = alphabet.IndexOf(char.ToLower(c));
            if (index == -1)
            {
                return c;
            }

            int newIndex = (index + shift + alphabet.Length) % alphabet.Length;
            if (newIndex < 0)
            {
                newIndex += alphabet.Length;
            }

            char shiftedChar = char.IsUpper(c) ? char.ToUpper(alphabet[newIndex]) : alphabet[newIndex];
            return shiftedChar;
        }
    }

}
