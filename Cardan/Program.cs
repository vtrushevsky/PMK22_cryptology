using System.Text;

string outputFilePath = @"D:\cryptology\PMK22_cryptology\Cardan\output.txt";
string inputFilePath = @"D:\cryptology\PMK22_cryptology\Cardan\input.txt";
int keySize = 4;
bool[,] key = GenerateRandomKey(keySize);

// bool[,] key = new bool[,] { { true, false, true, false },
//                             { false, true, false, true },
//                             { true, false, true, false },
//                             { false, true, false, true } };

string inputText = File.ReadAllText(inputFilePath);
string encryptedText = EncryptWithCardanoGrille(inputText, key);
File.WriteAllText(outputFilePath, encryptedText);

Console.WriteLine("Encryption completed. Check the output file.");

string decryptedText = DecryptWithCardanoGrille(encryptedText, key);
Console.WriteLine("Decrypted text: " + decryptedText);

string keyFilePath = @"D:\cryptology\PMK22_cryptology\Cardan\key.txt";
ExportKey(key, keyFilePath);
bool[,] importedKey = ImportKey(keyFilePath, keySize);

Console.ReadLine();


static string EncryptWithCardanoGrille(string plainText, bool[,] key)
{
    int keySize = key.GetLength(0);
    int blockSize = keySize * keySize;
    int totalBlocks = (plainText.Length + blockSize - 1) / blockSize;

    var encryptedBlocks = Enumerable.Range(0, totalBlocks)
                                    .AsParallel()
                                    .Select(i => plainText.Substring(i * blockSize, Math.Min(blockSize, plainText.Length - i * blockSize)))
                                    .Select(block => EncryptBlock(block, key))
                                    .ToArray();

    return string.Concat(encryptedBlocks);
}

static string DecryptWithCardanoGrille(string cipherText, bool[,] key)
{
    int keySize = key.GetLength(0);
    int blockSize = keySize * keySize;
    int totalBlocks = (cipherText.Length + blockSize - 1) / blockSize;

    var decryptedBlocks = Enumerable.Range(0, totalBlocks)
                                    .AsParallel()
                                    .Select(i => cipherText.Substring(i * blockSize, Math.Min(blockSize, cipherText.Length - i * blockSize)))
                                    .Select(block => DecryptBlock(block, key))
                                    .ToArray();

    return string.Concat(decryptedBlocks);
}

static string EncryptBlock(string block, bool[,] key)
{
    int keySize = key.GetLength(0);
    char[] encryptedChars = new char[keySize * keySize];

    int k = 0;
    for (int i = 0; i < keySize; i++)
    {
        for (int j = 0; j < keySize; j++)
        {
            if (key[i, j])
            {
                encryptedChars[k++] = block.Length > i * keySize + j ? block[i * keySize + j] : '_';
            }
        }
    }

    return new string(encryptedChars);
}

static string DecryptBlock(string block, bool[,] key)
{
    int keySize = key.GetLength(0);
    char[] decryptedChars = new char[keySize * keySize];

    int k = 0;
    for (int i = 0; i < keySize; i++)
    {
        for (int j = 0; j < keySize; j++)
        {
            if (key[i, j])
            {
                decryptedChars[i * keySize + j] = block.Length > k ? block[k] : '_';
                k++;
            }
        }
    }

    return new string(decryptedChars).TrimEnd('_');
}

static bool[,] GenerateRandomKey(int keySize)
{
    bool[,] key = new bool[keySize, keySize];
    Random rand = new Random();

    for (int i = 0; i < keySize; i++)
    {
        for (int j = 0; j < keySize; j++)
        {
            key[i, j] = rand.Next(2) == 1;
        }
    }

    return key;
}

static void ExportKey(bool[,] key, string filePath)
{
    int keySize = key.GetLength(0);
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < keySize; i++)
    {
        for (int j = 0; j < keySize; j++)
        {
            sb.Append(key[i, j] ? "1" : "0");
        }
        sb.AppendLine();
    }

    File.WriteAllText(filePath, sb.ToString());
}

static bool[,] ImportKey(string filePath, int keySize)
{
    string[] lines = File.ReadAllLines(filePath);
    bool[,] key = new bool[keySize, keySize];

    for (int i = 0; i < keySize; i++)
    {
        string line = lines[i];
        for (int j = 0; j < keySize; j++)
        {
            key[i, j] = line[j] == '1';
        }
    }

    return key;
}

