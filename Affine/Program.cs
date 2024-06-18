using System.Numerics;
using System.Text;

string inputFilePath = @"D:\cryptology\PMK22_cryptology\Affine\input.txt";
string outputFilePath = @"D:\cryptology\PMK22_cryptology\Affine\output.txt";
Console.WriteLine("Key: ");
int keySize = int.Parse(Console.ReadLine());
BigInteger[] key = GenerateRandomKey(keySize);
// BigInteger[] key = { 3, 7, 11, 19 };

string inputText = File.ReadAllText(inputFilePath);
string encryptedText = Encrypt(inputText, key, 26);
File.WriteAllText(outputFilePath, encryptedText);

Console.WriteLine("Encryption completed");

string decryptedText = DecryptWithHigherOrderAffineCipher(encryptedText, key, 26);
Console.WriteLine("Decrypted text: " + decryptedText);

string keyFilePath = "key.txt";
ExportKey(key, keyFilePath);
BigInteger[] importedKey = ImportKey(keyFilePath);

Console.ReadLine();

static string Encrypt(string plainText, BigInteger[] key, int alphabetSize)
{
    int keySize = key.Length;
    int blockSize = alphabetSize;
    int totalBlocks = (plainText.Length + blockSize - 1) / blockSize;

    var encryptedBlocks = Enumerable.Range(0, totalBlocks)
                                    .AsParallel()
                                    .Select(i => plainText.Substring(i * blockSize, Math.Min(blockSize, plainText.Length - i * blockSize)))
                                    .Select(block => EncryptBlock(block, key, alphabetSize))
                                    .ToArray();

    return string.Concat(encryptedBlocks);
}

static string DecryptWithHigherOrderAffineCipher(string cipherText, BigInteger[] key, int alphabetSize)
{
    int keySize = key.Length;
    int blockSize = alphabetSize;
    int totalBlocks = (cipherText.Length + blockSize - 1) / blockSize;

    var decryptedBlocks = Enumerable.Range(0, totalBlocks)
                                    .AsParallel()
                                    .Select(i => cipherText.Substring(i * blockSize, Math.Min(blockSize, cipherText.Length - i * blockSize)))
                                    .Select(block => DecryptBlock(block, key, alphabetSize))
                                    .ToArray();

    return string.Concat(decryptedBlocks);
}

static string EncryptBlock(string block, BigInteger[] key, int alphabetSize)
{
    int keySize = key.Length;
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < block.Length; i++)
    {
        char c = block[i];
        int index = char.IsLetter(c) ? char.ToLower(c) - 'a' : -1;

        if (index == -1)
        {
            sb.Append(c);
            continue;
        }

        BigInteger encryptedIndex = 0;
        for (int j = 0; j < keySize; j++)
        {
            encryptedIndex = (encryptedIndex + BigInteger.Pow(index, j + 1) * key[j]) % alphabetSize;
        }

        sb.Append((char)('a' + (int)encryptedIndex));
    }

    return sb.ToString();
}

static string DecryptBlock(string block, BigInteger[] key, int alphabetSize)
{
    int keySize = key.Length;
    BigInteger[] inversedKey = new BigInteger[keySize];
    ExtendedEuclidean(key, alphabetSize, out inversedKey);

    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < block.Length; i++)
    {
        char c = block[i];
        int index = char.IsLetter(c) ? char.ToLower(c) - 'a' : -1;

        if (index == -1)
        {
            sb.Append(c);
            continue;
        }

        BigInteger decryptedIndex = 0;
        for (int j = 0; j < keySize; j++)
        {
            decryptedIndex = (decryptedIndex + inversedKey[j] * BigInteger.Pow(index, keySize - j)) % alphabetSize;
        }

        sb.Append((char)('a' + (int)decryptedIndex));
    }

    return sb.ToString();
}

static BigInteger[] GenerateRandomKey(int keySize)
{
    Random rand = new Random();
    BigInteger[] key = new BigInteger[keySize];

    for (int i = 0; i < keySize; i++)
    {
        key[i] = rand.Next(1, 26);
    }

    return key;
}

static void ExportKey(BigInteger[] key, string filePath)
{
    StringBuilder sb = new StringBuilder();

    foreach (BigInteger k in key)
    {
        sb.Append(k.ToString() + " ");
    }

    File.WriteAllText(filePath, sb.ToString().TrimEnd());
}

static BigInteger[] ImportKey(string filePath)
{
    string[] keyParts = File.ReadAllText(filePath).Split(' ');
    BigInteger[] key = new BigInteger[keyParts.Length];

    for (int i = 0; i < keyParts.Length; i++)
    {
        key[i] = BigInteger.Parse(keyParts[i]);
    }

    return key;
}

static void ExtendedEuclidean(BigInteger[] key, int modulus, out BigInteger[] inversedKey)
{
    int keySize = key.Length;
    inversedKey = new BigInteger[keySize];

    for (int i = 0; i < keySize; i++)
    {
        BigInteger a = key[i];
        BigInteger b = modulus;
        BigInteger x = 1, y = 0;
        ExtendedEuclideanHelper(a, b, out x, out y);
        inversedKey[i] = x < 0 ? x + modulus : x;
    }
}

static void ExtendedEuclideanHelper(BigInteger a, BigInteger b, out BigInteger x, out BigInteger y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }

    BigInteger x1, y1;
    ExtendedEuclideanHelper(b, a % b, out x1, out y1);
    x = y1;
    y = x1 - (a / b) * y1;
}