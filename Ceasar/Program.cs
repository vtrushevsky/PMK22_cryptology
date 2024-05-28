string inputFilePath = @"D:\cryptology\shifting\input.txt";
string outputFilePath = @"D:\cryptology\shifting\output.txt";
string outputCFilePath = @"D:\cryptology\shifting\Coutput.txt";

Console.WriteLine("Key: ");
int shift = int.Parse(Console.ReadLine());
Console.WriteLine("BlockSize: ");
int blockSize = int.Parse(Console.ReadLine());

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string inputText = File.ReadAllText(inputFilePath);

string encryptedText = EncryptFileWithCaesarCipher(inputText, alphabet, shift, blockSize);
string decryptedText = EncryptFileWithCaesarCipher(inputText, alphabet, shift*-1, blockSize);
File.WriteAllText(outputFilePath, encryptedText);

Console.WriteLine("Encryption completed");


static string EncryptFileWithCaesarCipher(string text, string alphabet, int shift, int blockSize)
{
    if (blockSize == 0)
    {
        return EncryptStringWithCaesarCipher(text, alphabet, shift);
    }

    int totalBlocks = (text.Length + blockSize - 1) / blockSize;
    var blocks = Enumerable.Range(0, totalBlocks)
                            .AsParallel()
                            .Select(i => text.Substring(i * blockSize, Math.Min(blockSize, text.Length - i * blockSize)))
                            .Select(block => EncryptStringWithCaesarCipher(block, alphabet, shift))
                            .ToArray();

    return string.Concat(blocks);
}

static string EncryptStringWithCaesarCipher(string text, string alphabet, int shift)
{
    var encryptedChars = text.Select(c => ShiftChar(c, alphabet, shift));
    return new string(encryptedChars.ToArray());
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
