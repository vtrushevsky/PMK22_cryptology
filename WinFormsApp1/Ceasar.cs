namespace WinFormsApp1
{
    internal class Ceasar
    {
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        public string inputText { get; set; }
        public string outPath { get; set; }
        public int Key { get; set; }
        public int blockSize { get; set; }

        public Ceasar(string input, string output, int key, int blocksize)
        {
            inputText = File.ReadAllText(input);
            outPath = output;
            Key = key;
            blockSize = blocksize;
        }

        public void Encrypt()
        {
            if (blockSize == 0)
            {
                File.WriteAllText(outPath, EncryptStringWithCaesarCipher(inputText, alphabet, Key));
            }
            else
            {
                int totalBlocks = (inputText.Length + blockSize - 1) / blockSize;
                var blocks = Enumerable.Range(0, totalBlocks)
                                        .AsParallel()
                                        .Select(i => inputText.Substring(i * blockSize, Math.Min(blockSize, inputText.Length - i * blockSize)))
                                        .Select(block => EncryptStringWithCaesarCipher(block, alphabet, Key))
                                        .ToArray();

                File.WriteAllText(outPath, string.Concat(blocks));
            }
        }

        public void Decrypt()
        {
            if (blockSize == 0)
            {
                File.WriteAllText(outPath, DecryptStringWithCaesarCipher(inputText, alphabet, Key));
            }
            else
            {
                int totalBlocks = (inputText.Length + blockSize - 1) / blockSize;
                var blocks = Enumerable.Range(0, totalBlocks)
                                        .AsParallel()
                                        .Select(i => inputText.Substring(i * blockSize, Math.Min(blockSize, inputText.Length - i * blockSize)))
                                        .Select(block => DecryptStringWithCaesarCipher(block, alphabet, Key))
                                        .ToArray();

                File.WriteAllText(outPath, string.Concat(blocks));
            }
        }

        static string EncryptStringWithCaesarCipher(string text, string alphabet, int shift)
        {
            var encryptedChars = text.Select(c => ShiftChar(c, alphabet, shift));
            return new string(encryptedChars.ToArray());
        }

        static string DecryptStringWithCaesarCipher(string text, string alphabet, int shift)
        {
            var decryptedChars = text.Select(c => ShiftChar(c, alphabet, -shift));
            return new string(decryptedChars.ToArray());
        }

        static char ShiftChar(char c, string alphabet, int shift)
        {
            int index = alphabet.IndexOf(c);
            if (index == -1)
            {
                return c;
            }

            int newIndex = (index + shift) % alphabet.Length;
            if (newIndex < 0)
            {
                newIndex += alphabet.Length;
            }

            return alphabet[newIndex];
        }
    }

}
