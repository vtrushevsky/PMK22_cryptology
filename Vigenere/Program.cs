using System;

int[,] A = {
        { 3, 3 },
        { 2, 5 }
        };

// Вектор зсуву b
int[] b = { 1, 4 };

// Відкритий текст (довжина повинна бути кратною 2)
string plainText = "HELLO";

// Якщо довжина тексту непарна, додаємо пробіл
if (plainText.Length % 2 != 0)
{
    plainText += "X";
}

string encryptedText = Encrypt(plainText, A, b);
string decryptedText = Decrypt(encryptedText, A, b);

Console.WriteLine("Відкритий текст: " + plainText);
Console.WriteLine("Зашифрований текст: " + encryptedText);
Console.WriteLine("Розшифрований текст: " + decryptedText);

// Метод для обчислення оберненої матриці за модулем 26
static int[,] InverseMatrix(int[,] matrix)
{
    int det = Determinant(matrix);
    int detInv = ModInverse(det, 26);
    int[,] adjugate = Adjugate(matrix);

    int[,] inverse = new int[2, 2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            inverse[i, j] = (adjugate[i, j] * detInv) % 26;
            if (inverse[i, j] < 0)
            {
                inverse[i, j] += 26;
            }
        }
    }

    return inverse;
}

// Метод для обчислення визначника матриці
static int Determinant(int[,] matrix)
{
    return (matrix[0, 0] * matrix[1, 1] - matrix[0, 1] * matrix[1, 0]) % 26;
}

// Метод для обчислення матриці алгебраїчних доповнень
static int[,] Adjugate(int[,] matrix)
{
    int[,] adjugate = new int[2, 2];
    adjugate[0, 0] = matrix[1, 1];
    adjugate[0, 1] = -matrix[0, 1];
    adjugate[1, 0] = -matrix[1, 0];
    adjugate[1, 1] = matrix[0, 0];

    return adjugate;
}

// Метод для обчислення оберненого за модулем числа
static int ModInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }
    throw new ArgumentException("No modular inverse exists.");
}

// Метод для шифрування тексту
static string Encrypt(string plainText, int[,] A, int[] b)
{
    int n = plainText.Length;
    char[] encryptedText = new char[n];

    for (int i = 0; i < n; i += 2)
    {
        int x1 = plainText[i] - 'A';
        int x2 = plainText[i + 1] - 'A';

        int y1 = (A[0, 0] * x1 + A[0, 1] * x2 + b[0]) % 26;
        int y2 = (A[1, 0] * x1 + A[1, 1] * x2 + b[1]) % 26;

        encryptedText[i] = (char)('A' + y1);
        encryptedText[i + 1] = (char)('A' + y2);
    }

    return new string(encryptedText);
}

// Метод для дешифрування тексту
static string Decrypt(string cipherText, int[,] A, int[] b)
{
    int[,] A_inv = InverseMatrix(A);
    int n = cipherText.Length;
    char[] decryptedText = new char[n];

    for (int i = 0; i < n; i += 2)
    {
        int y1 = cipherText[i] - 'A';
        int y2 = cipherText[i + 1] - 'A';

        int x1 = (A_inv[0, 0] * (y1 - b[0]) + A_inv[0, 1] * (y2 - b[1])) % 26;
        int x2 = (A_inv[1, 0] * (y1 - b[0]) + A_inv[1, 1] * (y2 - b[1])) % 26;

        if (x1 < 0) x1 += 26;
        if (x2 < 0) x2 += 26;

        decryptedText[i] = (char)('A' + x1);
        decryptedText[i + 1] = (char)('A' + x2);
    }

    return new string(decryptedText);
}
