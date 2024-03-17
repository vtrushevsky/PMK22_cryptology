using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string encryptedText = "Pm ol ohk hufaopun jvumpkluaphs av zhf";
        string[] dictionary = File.ReadAllLines("D:\\MyProgects\\shifer\\shiferrr\\Betta\\english_words.txt");

        int maxShift = 26;
        int maxCount = 0;
        string result = "";
        int bestShift = 0;


        for (int shift = 1; shift <= maxShift; shift++)
        {
            string decryptedText = DecryptData(encryptedText, shift);
            int count = CountWordsInDictionary(decryptedText, dictionary);



            if (count > maxCount)
            {
                maxCount = count;
                result = decryptedText;
                bestShift = shift;
            }
        }

        Console.WriteLine($"Найкращий результат: {result}, Знайдено слів в словнику: {maxCount},Ключ: {bestShift}");
    }

    public static char cipher(char ch, int key)
    {
        if (!char.IsLetter(ch))
        {

            return ch;
        }

        char d = char.IsUpper(ch) ? 'A' : 'a';
        return (char)((((ch + key) - d) % 26) + d);


    }


    public static string EncryptData(string input, int key)
    {
        string output = string.Empty;

        foreach (char ch in input)
            output += cipher(ch, key);

        return output;
    }
    public static string DecryptData(string input, int key)
    {
        return EncryptData(input, 26 - key);
    }

    static int CountWordsInDictionary(string text, string[] dictionary)
    {
        string[] words = text.Split(new[] { ' ', '.', ',', ';', ':', '!', '?' }, StringSplitOptions.RemoveEmptyEntries);
        int count = 0;

        foreach (var word in words)
        {
            if (dictionary.Any(dictWord => dictWord.ToLower() == word.ToLower()))
            {
                count++;
            }
        }

        return count;
    }
}






