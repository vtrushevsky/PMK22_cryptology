using System.Text;

string inputFilePath = @"D:\cryptology\PMK22_cryptology\Vigenere\input.txt";
string outputFilePath = @"D:\cryptology\PMK22_cryptology\Vigenere\output.txt";

Console.WriteLine("Key: ");
string key = Console.ReadLine();
Console.WriteLine("BlockSize: ");
int blockSize = int.Parse(Console.ReadLine());

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string inputText = File.ReadAllText(inputFilePath);

string encryptedText = EncryptWithVigenereCipher(inputText, alphabet, key);
File.WriteAllText(outputFilePath, encryptedText);

Console.WriteLine("Encryption completed");

int detectedKeyLength = DetectKeyLengthWithKasiskiExamination(encryptedText, alphabet);
Console.WriteLine($"Detected key length: {detectedKeyLength}");

string detectedKey = BreakVigenereCipherWithDictionary(encryptedText, alphabet, detectedKeyLength, "dictionary.txt");
Console.WriteLine($"Detected key: {detectedKey}");

string decryptedText = EncryptWithVigenereCipher(encryptedText, alphabet, detectedKey, false);
Console.WriteLine("Decrypted text: " + decryptedText);

Console.ReadLine();


static string EncryptWithVigenereCipher(string plainText, string alphabet, string key, bool encrypt = true)
{
    int keyLength = key.Length;
    int blockSize = alphabet.Length;
    int totalBlocks = (plainText.Length + blockSize - 1) / blockSize;

    var encryptedBlocks = Enumerable.Range(0, totalBlocks)
                                    .AsParallel()
                                    .Select(i => plainText.Substring(i * blockSize, Math.Min(blockSize, plainText.Length - i * blockSize)))
                                    .Select(block => EncryptBlock(block, key, alphabet, encrypt))
                                    .ToArray();

    return string.Concat(encryptedBlocks);
}

static string EncryptBlock(string block, string key, string alphabet, bool encrypt)
{
    StringBuilder sb = new StringBuilder();
    int keyLength = key.Length;
    int alphabetLength = alphabet.Length;

    for (int i = 0; i < block.Length; i++)
    {
        char c = block[i];
        int baseIndex = alphabet.IndexOf(c);
        if (baseIndex == -1)
        {
            sb.Append(c);
            continue;
        }

        int keyIndex = alphabet.IndexOf(key[i % keyLength]);
        int shift = encrypt ? keyIndex : -keyIndex;
        int newIndex = (baseIndex + shift) % alphabetLength;
        if (newIndex < 0)
        {
            newIndex += alphabetLength;
        }

        sb.Append(alphabet[newIndex]);
    }

    return sb.ToString();
}

static int DetectKeyLengthWithKasiskiExamination(string cipherText, string alphabet)
{
    int maxKeyLength = 20;
    int[] distances = new int[maxKeyLength];

    for (int i = 0; i < cipherText.Length - 3; i++)
    {
        string trigram = cipherText.Substring(i, 3);
        int j = cipherText.IndexOf(trigram, i + 1);
        if (j != -1)
        {
            int distance = j - i;
            for (int k = 1; k < maxKeyLength; k++)
            {
                if (distance % k == 0)
                {
                    distances[k]++;
                }
            }
        }
    }

    int maxCount = distances.Max();
    int keyLength = Array.IndexOf(distances, maxCount);

    return keyLength;
}

static string BreakVigenereCipherWithDictionary(string cipherText, string alphabet, int keyLength, string dictionaryFilePath)
{
    string[] words = File.ReadAllLines(dictionaryFilePath);
    char[] key = new char[keyLength];

    for (int i = 0; i < keyLength; i++)
    {
        Dictionary<char, int> frequencies = new Dictionary<char, int>();
        foreach (char c in alphabet)
        {
            frequencies[c] = 0;
        }

        for (int j = i; j < cipherText.Length; j += keyLength)
        {
            char c = cipherText[j];
            if (alphabet.Contains(c))
            {
                frequencies[c]++;
            }
        }

        char maxChar = frequencies.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
        int maxIndex = alphabet.IndexOf(maxChar);
        int shift = alphabet.IndexOf('e') - maxIndex;
        if (shift < 0)
        {
            shift += alphabet.Length;
        }

        key[i] = alphabet[(alphabet.IndexOf('a') + shift) % alphabet.Length];
    }

    string decryptedText = EncryptWithVigenereCipher(cipherText, alphabet, new string(key), false);

    foreach (string word in words)
    {
        if (decryptedText.Contains(word))
        {
            return new string(key);
        }
    }

    return string.Empty;
}
