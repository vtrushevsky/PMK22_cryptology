using System;
using System.IO;
using System.Collections.Generic;
using System.Diagnostics;

class RailFenceEncryption
{
    static string EncryptRailFence(string plainText, int key, int blockSize)
    {
        List<char> result = new List<char>();

        if (key == blockSize)
            throw new ArgumentException("Block size cannot be equal to key.");

        if (string.IsNullOrEmpty(plainText))
            throw new ArgumentException("Text cannot be empty.");

        if (key <= 1)
            throw new ArgumentException("Key must be higher than one.");

        if (blockSize <= 0)
            blockSize = plainText.Length;

        for (int index = 0; index < plainText.Length; index += blockSize)
        {
            string block = plainText.Substring(index, Math.Min(blockSize, plainText.Length - index));

            char[,] rail = new char[key, block.Length];
            bool isDirectionDown = true;
            int row = key - 1, col = 0;

            for (int jIndex = 0; jIndex < block.Length; jIndex++)
            {
                if (row == 0 || row == key - 1)
                    isDirectionDown = !isDirectionDown;

                rail[row, col] = block[jIndex];
                col++;

                if (isDirectionDown)
                    row++;
                else
                    row--;
            }

            for (int i = 0; i < key; i++)
            {
                for (int j = 0; j < block.Length; j++)
                {
                    if (rail[i, j] != '\0')
                        result.Add(rail[i, j]);
                }
            }
        }

        return new string(result.ToArray());
    }

    static string DecryptRailFence(string encryptedText, int key, int blockSize)
    {
        List<char> result = new List<char>();

        for (int i = 0; i < encryptedText.Length; i += blockSize)
        {
            string block = encryptedText.Substring(i, Math.Min(blockSize, encryptedText.Length - i));

            char[,] rail = new char[key, block.Length];
            bool dirDown = true;
            int row = key - 1, col = 0;

            for (int j = 0; j < block.Length; j++)
            {
                if (row == 0)
                    dirDown = true;
                if (row == key - 1)
                    dirDown = false;

                rail[row, col] = '*';
                col++;

                if (dirDown)
                    row++;
                else
                    row--;
            }

            int index = 0;
            for (int j = 0; j < key; j++)
            {
                for (int k = 0; k < block.Length; k++)
                {
                    if (rail[j, k] == '*' && index < block.Length)
                    {
                        rail[j, k] = block[index];
                        index++;
                    }
                }
            }

            row = key - 1;
            col = 0;
            for (int j = 0; j < block.Length; j++)
            {
                if (row == 0)
                    dirDown = true;
                if (row == key - 1)
                    dirDown = false;

                if (rail[row, col] != '*')
                {
                    result.Add(rail[row, col]);
                    col++;
                }

                if (dirDown)
                    row++;
                else
                    row--;
            }
        }

        return new string(result.ToArray());
    }

    static void Main()
    {
        while (true)
        {
            Console.WriteLine("Menu:");
            Console.WriteLine("1. Encrypt Text");
            Console.WriteLine("2. Decrypt Text");
            Console.WriteLine("3. Encrypt Text File");
            Console.WriteLine("4. Decrypt Text File");
            Console.WriteLine("5. Exit");

            Console.Write("Select action (1-5): ");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Console.Write("Enter the text to encrypt: ");
                    string textToEncrypt = Console.ReadLine();
                    Console.Write("Enter the key (height of the fence): ");
                    int key = int.Parse(Console.ReadLine());
                    Console.Write("Enter the block size: ");
                    int blockSize = int.Parse(Console.ReadLine());
                    Console.WriteLine(EncryptRailFence(textToEncrypt, key, blockSize));
                    break;
                case "2":
                    Console.Write("Enter the text to decrypt: ");
                    string textToDecrypt = Console.ReadLine();
                    Console.Write("Enter the key (height of the fence): ");
                    key = int.Parse(Console.ReadLine());
                    Console.Write("Enter the block size: ");
                    blockSize = int.Parse(Console.ReadLine());
                    Console.WriteLine(DecryptRailFence(textToDecrypt, key, blockSize));
                    break;
                case "3":
                    Console.Write("Enter the name of the text file to encrypt: ");
                    string fileToEncrypt = Console.ReadLine();
                    Console.Write("Enter the key (height of the fence): ");
                    key = int.Parse(Console.ReadLine());
                    Console.Write("Enter the block size: ");
                    blockSize = int.Parse(Console.ReadLine());
                    string textFromFile = File.ReadAllText(fileToEncrypt).Replace("\n", "\t");
                    File.WriteAllText("encrypted.txt", EncryptRailFence(textFromFile, key, blockSize));
                    break;
                case "4":
                    Console.Write("Enter the name of the text file to decrypt: ");
                    string fileToDecrypt = Console.ReadLine();
                    Console.Write("Enter the key (height of the fence): ");
                    key = int.Parse(Console.ReadLine());
                    Console.Write("Enter the block size: ");
                    blockSize = int.Parse(Console.ReadLine());
                    textFromFile = File.ReadAllText(fileToDecrypt);
                    File.WriteAllText("decrypted.txt", DecryptRailFence(textFromFile, key, blockSize));
                    break;
                case "5":
                    Console.WriteLine("Thank you for using the program!");
                    return;
                default:
                    Console.WriteLine("Please select a valid action (1-5).");
                    break;
            }
        }
    }
}
