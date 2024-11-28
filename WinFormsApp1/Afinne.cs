using System.Numerics;

public class Affine
{
    private int[,] KeyMatrix;
    private int[] KeyVector;
    private int Modulus = 26;
    private string InputFilePath;
    private string OutputFilePath;
    private string KeyM;
    private string KeyV;
    private int size;

    public Affine(int sz, string inputFilePath, string outputFilePath, string keyM, string keyV)
    {
        size = sz;
        InputFilePath = inputFilePath;
        OutputFilePath = outputFilePath;
        KeyM = keyM;
        KeyV = keyV;
    }

    public void SaveKeys()
    {
        using (StreamWriter writer = new StreamWriter(KeyM))
        {
            for (int i = 0; i < KeyMatrix.GetLength(0); i++)
            {
                for (int j = 0; j < KeyMatrix.GetLength(1); j++)
                {
                    writer.Write(KeyMatrix[i, j] + " ");
                }
                writer.WriteLine();
            }
        }

        using (StreamWriter writer = new StreamWriter(KeyV))
        {
            foreach (var value in KeyVector)
            {
                writer.WriteLine(value);
            }
        }
    }

    public void LoadKeys(string matrixFilePath, string vectorFilePath)
    {
        var matrixLines = File.ReadAllLines(matrixFilePath);
        var vectorLines = File.ReadAllLines(vectorFilePath);

        int size = matrixLines.Length;
        KeyMatrix = new int[size, size];
        KeyVector = new int[size];

        for (int i = 0; i < size; i++)
        {
            var values = matrixLines[i].Split(' ', StringSplitOptions.RemoveEmptyEntries)
                                        .Select(int.Parse)
                                        .ToArray();
            for (int j = 0; j < size; j++)
            {
                KeyMatrix[i, j] = values[j];
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (!string.IsNullOrWhiteSpace(vectorLines[i]))
            {
                KeyVector[i] = int.Parse(vectorLines[i]);
            }
        }
    }

    public async Task<string> Encrypt()
    {
        GenerateKeys(size, Modulus);
        SaveKeys();
        string plaintext = File.ReadAllText(InputFilePath);

        string cipertext = await Task.Run(() => Encrypt(plaintext));
        File.WriteAllText(OutputFilePath, cipertext);
        return cipertext;
    }

    private string Encrypt(string plaintext)
    {
        int size = KeyVector.Length;
        char[] encrypted = new char[plaintext.Length];

        for (int i = 0; i < plaintext.Length; i++)
        {
            int charValue = (int)plaintext[i];
            int newValue = 0;

            for (int j = 0; j < size; j++)
            {
                newValue += KeyMatrix[i % size, j] * charValue;
            }
            newValue += KeyVector[i % size];
            newValue %= Modulus;

            encrypted[i] = (char)newValue;
        }

        return new string(encrypted);
    }

    public async Task<string> Decrypt()
    {
        string ciphertext = File.ReadAllText(InputFilePath);
        string decrypted = await Task.Run(() => Decrypt(ciphertext));
        File.WriteAllText(OutputFilePath, decrypted);
        return decrypted;
    }

    private string Decrypt(string ciphertext)
    {
        int size = KeyVector.Length;
        char[] decrypted = new char[ciphertext.Length];

        for (int i = 0; i < ciphertext.Length; i++)
        {
            int charValue = (int)ciphertext[i];
            int newValue = 0;

            for (int j = 0; j < size; j++)
            {
                int invValue = ModularInverse(KeyMatrix[i % size, j], Modulus);
                newValue += invValue * (charValue - KeyVector[i % size] + Modulus) % Modulus;
            }
            newValue %= Modulus;

            decrypted[i] = (char)newValue;
        }

        return new string(decrypted);
    }

    private void GenerateKeys(int size, int modulus)
    {
        Random rand = new Random();
        bool isInvertible;
        do
        {
            KeyMatrix = new int[size, size];
            KeyVector = new int[size];

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    KeyMatrix[i, j] = rand.Next(modulus);
                }
            }

            for (int j = 0; j < size; j++)
            {
                KeyVector[j] = rand.Next(modulus);
            }

            isInvertible = IsMatrixInvertible(KeyMatrix, modulus);
        } while (!isInvertible);
    }

    private bool IsMatrixInvertible(int[,] matrix, int modulus)
    {
        BigInteger det = Determinant(matrix, modulus);
        BigInteger modDet = BigInteger.Remainder(det, modulus);
        return modDet != 0;
    }

    private int Determinant(int[,] matrix, int modulus)
    {
        int size = matrix.GetLength(0);
        BigInteger det = 1;

        for (int i = 0; i < size; i++)
        {
            int pivot = matrix[i, i];
            if (pivot == 0)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (matrix[j, i] != 0)
                    {
                        SwapRows(matrix, i, j);
                        det = BigInteger.Negate(det);
                        break;
                    }
                }
                pivot = matrix[i, i];
            }

            det = BigInteger.Multiply(det, pivot);

            for (int j = i + 1; j < size; j++)
            {
                int factor = (int)(BigInteger.Remainder(matrix[j, i], modulus) * ModularInverse(pivot, modulus) % modulus);
                for (int k = i; k < size; k++)
                {
                    matrix[j, k] -= factor * matrix[i, k];
                    matrix[j, k] %= modulus;
                    if (matrix[j, k] < 0)
                    {
                        matrix[j, k] += modulus; 
                    }
                }
            }
        }

        return (int)(det % modulus);
    }


    private int ModularInverse(int a, int m)
    {
        for (int x = 1; x < m; x++)
        {
            if ((a * x) % m == 1)
            {
                return x;
            }
        }
        throw new InvalidOperationException("Обернений елемент не існує.");
    }

    private void SwapRows(int[,] matrix, int i, int j)
    {
        int size = matrix.GetLength(0);
        for (int k = 0; k < size; k++)
        {
            int temp = matrix[i, k];
            matrix[i, k] = matrix[j, k];
            matrix[j, k] = temp;
        }
    }
}
