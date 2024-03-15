namespace CipherRailFence
{
    internal class CipherRailFenceClass
    {
        public static string Encrypted(string msg, int h, int blockLength)
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

            Parallel.ForEach(blocks, block =>
            {
                    for (int i = 0; i < h; i++)
                    {
                        for (int j = h - i - 1; j < block.Length; j += h)
                            result += block[j];
                    }
                
            });

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

            Parallel.ForEach(blocks, block =>
            {
                if (key == 2)
                {
                    int halfLength = block.Length / 2;
                    string firstHalf = block.Substring(0, halfLength);
                    string secondHalf = block.Substring(halfLength);

                    for (int i = 0; i < halfLength; i++)
                    {
                        result += secondHalf[i];
                        result += firstHalf[i];
                    }

                    if (block.Length % 2 == 1)
                    {
                        result += secondHalf[halfLength];
                    }
                }
                else
                {
                    result = block;
                    int k = 0;
                    for (int i = 0; i < key; i++)
                    {
                        //for (int j = 0; i + j < block.Length; j += key)
                        //{
                        //    result = result.Substring(0, i + j) + block[k++] + result.Substring(i + j + 1);
                        //}

                        for (int j = key - i - 1; j < block.Length; j += key)
                        {
                            result = result.Substring(0, j) + block[k++] + result.Substring(j + 1);
                        }
                    }
                }
            });

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

        //public static string DecryptFileWithoutKey(string file_path_encrypted, string file_path_decrypted)
        //{
        //    string encrypted_file = ReadTextFile(file_path_encrypted);
        //    string[] dictionary = File.ReadAllLines(@"D:\Навчання\Шарпи\WinFormsApp1\WinFormsApp1\words.txt");

        //    for (int i = 1; i < encrypted_file.Length; i++)
        //    {
        //        string maybe_decrypt = Decrypted(encrypted_file, i, 0);

        //        foreach (var entry in dictionary)
        //        {
        //            if (maybe_decrypt.Contains(entry) || entry.Length >= 3)
        //            {
        //                string all_decrypted = Decrypted(encrypted_file, i, 0);
        //                WriteToFile(file_path_decrypted, all_decrypted);
        //                return "Decrypted successfully";
        //            }
        //        }
        //    }

        //    return "Failde to decrypt";
        //}
    }
}