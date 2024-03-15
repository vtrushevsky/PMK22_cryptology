using System;

namespace CipherCaesar
{
    internal class CipherCaesarClass
    {
        const string UA_ALFABET = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
        static string shifted_ua_alfabet = "";
        const string EN_ALFABET = "abcdefghijklmnopqrstuvwxyz";
        static string shifted_en_alfabet = "";

        private static void ShiftUaAlphabet(int key)
        {
            char[] new_alpabet = new char[33];
            for (int i = 0; i < new_alpabet.Length; i++)
            {
                if (i + key >= 33)
                {
                    int index = (i + key) % UA_ALFABET.Length;
                    new_alpabet[i] = UA_ALFABET[index];
                }
                else if (i + key < 33)
                    new_alpabet[i] = UA_ALFABET[i + key];
            }

            shifted_ua_alfabet = new string(new_alpabet);
        }

        private static void ShiftEnAlphabet(int key)
        {
            char[] new_alpabet = new char[26];
            for (int i = 0; i < new_alpabet.Length; i++)
            {
                if (i + key >= 26)
                {
                    int index = (i + key) % 26;
                    new_alpabet[i] = EN_ALFABET[index];
                }
                else
                    new_alpabet[i] = EN_ALFABET[i + key];
            }

            shifted_en_alfabet = new string(new_alpabet);
        }

        static bool IsUkrainian(string input)
        {
            foreach (char character in input)
            {
                if (character >= 0x0400 && character <= 0x04FF)
                {
                    return true;
                }
            }
            return false;
        }

        static bool IsEnglish(string input)
        {
            foreach (char character in input)
            {
                if ((character >= 0x0041 && character <= 0x005A) || (character >= 0x0061 && character <= 0x007A))
                {
                    return true;
                }
            }
            return false;
        }

        public static string Encrypted(string msg, int key, int blockLength)
        {
            if (blockLength == 0)
                blockLength = msg.Length;

            List<string> blocks = new List<string>();

            for (int i = 0; i < msg.Length; i += blockLength)
            {
                int length = Math.Min(blockLength, msg.Length - i);
                blocks.Add(msg.Substring(i, length));
            }

            string result = "";

            if (IsUkrainian(msg))
            {
                ShiftUaAlphabet(key);
                Parallel.ForEach(blocks, block =>
                {
                    for (int i = 0; i <  blockLength; i++)
                    //foreach (char symbol in block)
                    {
                        char symbol = block[i];
                        if (char.IsUpper(symbol))
                         symbol = char.ToLower(symbol);
                        
                        int index = UA_ALFABET.IndexOf(symbol);

                        if (index != -1)
                            result += shifted_ua_alfabet[index];

                        else
                            result += symbol;

                    }
                });
            }
            else if (IsEnglish(msg))
            {
                ShiftEnAlphabet(key);
                Parallel.ForEach(blocks, block =>
                {
                    for (int i = 0; i < blockLength; i++)
                        //foreach (char symbol in block)
                    {
                        char symbol = block[i];
                        if (char.IsUpper(symbol))
                            symbol = char.ToLower(symbol);

                        int index = EN_ALFABET.IndexOf(symbol);

                        if (index != -1)
                            result += shifted_en_alfabet[index];

                        else
                            result += symbol;

                    }
                });

            }

            return result;
        }

        public static string Decrypted(string msg, int key, int blockLength)
        {
            if (blockLength == 0)
                blockLength = msg.Length;

            List<string> blocks = new List<string>();

            for (int i = 0; i < msg.Length; i += blockLength)
            {
                int length = Math.Min(blockLength, msg.Length - i);
                blocks.Add(msg.Substring(i, length));
            }

            string result = "";

            if (IsUkrainian(msg))
            {
                ShiftUaAlphabet(key);
                Parallel.ForEach(blocks, block =>
                {

                    for (int i = 0; i < msg.Length; i++)
                    {
                        char currentChar = msg[i];
                        int index = UA_ALFABET.IndexOf(currentChar);

                        if (index != -1)
                        {
                            index -= key;
                            if (index < 0)
                                index = UA_ALFABET.Length + index;

                            result += UA_ALFABET[index];
                        }
                        else
                            result += currentChar;
                    }
                });
            }
            else if (IsEnglish(msg))
            {
                ShiftEnAlphabet(key);
                Parallel.ForEach(blocks, block =>
                {
                    for (int i = 0; i < msg.Length; i++)
                    {
                        char currentChar = msg[i];
                        int index = EN_ALFABET.IndexOf(currentChar);

                        if (index != -1)
                        {
                            index -= key;
                            if (index < 0)
                                index = EN_ALFABET.Length + index;

                            result += EN_ALFABET[index];
                        }
                        else
                            result += currentChar;
                    }
                });
            }

            return result;
        }


        public static string DecryptWithoutKey(string encrypted_word)
        {
            string[] dictionary = File.ReadAllLines(@"D:\Навчання\Шарпи\WinFormsApp1\WinFormsApp1\words.txt");
            string decrypted_word = "this word doesnt exist";

            for (int i = 1; i < encrypted_word.Length; i++)
            {
                string maybe_decrypt = Decrypted(encrypted_word, i, 0);

                if (dictionary.Contains(maybe_decrypt))
                    decrypted_word = maybe_decrypt;

            }

            return decrypted_word;
        }


    }
}