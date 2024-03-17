using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Threading.Tasks;
/*
class Program1
{
    public static char cipher(char ch, int key)
    {
        if (!char.IsLetter(ch))
        {

            return ch;
        }

        char d = char.IsUpper(ch) ? 'A' : 'a';
        return (char)((((ch + key) - d) % 26) + d);


    }


    public static string Encipher(string input, int key)
    {
        string output = string.Empty;

        foreach (char ch in input)
            output += cipher(ch, key);

        return output;
    }
    public static string Decipher(string input, int key)
    {
        return Encipher(input, 26 - key);
    }*/
    /*static void Main()
    {
        
        string inputFileName = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile1.txt";

       
        string outputFileName = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile3.txt";
        string outputFileName2 = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile1.txt";


        string input = File.ReadAllText(outputFileName);

        Console.WriteLine("Enter your number:");
        if (!int.TryParse(Console.ReadLine(), out int number))
        {
            Console.WriteLine("Invalid input for number.");
            return;
        }

        Console.WriteLine("Enter your block number:");
        if (!int.TryParse(Console.ReadLine(), out int chunkSize) || chunkSize <= 0)
        {
            Console.WriteLine("Invalid input for chunk size.");
            return;
        }

        List<string> chunks = new List<string>();
        Stopwatch stopwatch = new Stopwatch();
        stopwatch.Start();

        for (int i = 0; i < input.Length; i += chunkSize)
        {
            int length = Math.Min(chunkSize, input.Length - i);
            string chunk = input.Substring(i, length);
            chunks.Add(chunk);
        }

        string[] chunksArray = chunks.ToArray();

        Parallel.ForEach(chunksArray, (chunk, state, index) =>
        {
            chunksArray[index] = Decipher(chunk, number);
        });

        string result = string.Join("", chunksArray);

        stopwatch.Stop();
        File.WriteAllText(outputFileName2, result);

        Console.WriteLine($"Result has been written to {outputFileName2}");
        Console.WriteLine($"Elapsed time: {stopwatch.Elapsed}");
    }

    static string T1EncryptData(string decrData, int key)
    {
        if (key == 1) return decrData;
        var decrDataLength = decrData.Length;

        var decrVector = new int[decrDataLength];
        var delta = 1;
        var charPositionInEncryptedString = 0;
        for (var i = 0; i < decrDataLength; i++)
        {
            if (charPositionInEncryptedString > key - 2 || (charPositionInEncryptedString <= 0 && delta < 0)) delta = -delta;
            decrVector[i] = charPositionInEncryptedString;
            charPositionInEncryptedString += delta;
        }

        var res = new string[key];
        for (var i = 0; i < decrDataLength; i++)
        {
            for (var j = 0; j < key; j++)
            {
                if (decrVector[i] == j)
                    res[j] += decrData[i];
            }
        }

        var result = string.Empty;
        for (var i = res.Length - 1; i != -1; i--)
            result += res[i];

        return result;
    }

    static string DecryptData1(string encrData, int key)
    {
        if (key == 1) return encrData;

        var encrDataLength = encrData.Length;

        var decrVector = new int[encrDataLength];
        var delta = 1;
        var charPositionInEncryptedString = 0;

        for (var i = 0; i < encrDataLength; i++)
        {
            if (charPositionInEncryptedString > key - 2 || (charPositionInEncryptedString <= 0 && delta < 0))
                delta = -delta;
            decrVector[i] = charPositionInEncryptedString;
            charPositionInEncryptedString += delta;
        }

        var res = new char[encrDataLength];

        int index = 0;
        for (var i = 0; i < key; i++)
        {
            for (var j = 0; j < encrDataLength / key; j++)
            {
                res[index++] = encrData[i + j * key];
            }
        }

        return new string(res);
    }


}
*/
