string text = "Hello world, im cybersecurity";
int[,] matrix = { { 5, 8 }, { 17, 3 } }; 
int[] vector = { 8, 14 }; 
int abc = 26;


//GHIQNVJEMOCAUPDNPGGHQJFAXFFPRV
string encrypted = Encrypt(text, matrix, vector, abc);
Console.WriteLine($"Encrypted: {encrypted}");


static string Encrypt(string text, int[,] matrix, int[] vector, int abc)
{
    int blockSize = matrix.GetLength(0);
    string ciphertext = "";

    for (int i = 0; i < text.Length; i += blockSize)
    {
        int[] block = new int[blockSize];
        for (int j = 0; j < blockSize; j++)
        {
            block[j] = (i + j < text.Length) ? (text[i + j] - 'A') : ('X' - 'A');
        }

        int[] encryptedBlock = MxV(matrix, block, abc);
        for (int j = 0; j < encryptedBlock.Length; j++)
        {
            encryptedBlock[j] = (encryptedBlock[j] + vector[j]) % abc;
            ciphertext += (char)(encryptedBlock[j] + 'A');
        }
    }
    return ciphertext;
}

static int[] MxV(int[,] matrix, int[] vector, int m)
{
    int[] result = new int[vector.Length];

    for (int i = 0; i < matrix.GetLength(0); i++)
    {
        result[i] = 0;
        for (int j = 0; j < matrix.GetLength(1); j++)
        {
            result[i] += matrix[i, j] * vector[j];
        }
        result[i] = Module(result[i], m);
    }

    return result;
}

static int Module(int a, int m)
{
    int r = a % m;
    return r < 0 ? r + m : r;
}
