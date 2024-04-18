using System;
using System.IO;
using System.Collections.Generic;
using System.Windows.Forms;

namespace cryptology
{
    public partial class cardano : Form
    {
        private Button[,] buttonMatrix;
        private bool[,] keyGrid;

        public cardano()
        {
            InitializeComponent();
        }

        private void CreateButtonMatrix(int size)
        {
            // Видаляємо попередню матрицю кнопок, якщо вона існує
            if (buttonMatrix != null)
            {
                foreach (Button button in buttonMatrix)
                {
                    this.Controls.Remove(button);
                }
            }

            buttonMatrix = new Button[size, size];
            int buttonSize = 40; // Розмір кнопки
            int startX = 20; // Початкова позиція X першої кнопки
            int startY = 20; // Початкова позиція Y першої кнопки

            // Створення та вивід кнопок на форму
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Button button = new Button();
                    button.Size = new System.Drawing.Size(buttonSize, buttonSize);
                    button.Location = new System.Drawing.Point(startX + j * (buttonSize + 5), startY + i * (buttonSize + 5));
                    button.Click += Button_Click; // Додаємо обробник подій для кнопки
                    this.Controls.Add(button);
                    buttonMatrix[i, j] = button;
                }
            }
        }

        private void Button_Click(object sender, EventArgs e)
        {
            Button clickedButton = (Button)sender;
            int rowIndex = -1;
            int colIndex = -1;

            // Знаходимо індекси натиснутої кнопки
            for (int i = 0; i < buttonMatrix.GetLength(0); i++)
            {
                for (int j = 0; j < buttonMatrix.GetLength(1); j++)
                {
                    if (buttonMatrix[i, j] == clickedButton)
                    {
                        rowIndex = i;
                        colIndex = j;
                        break;
                    }
                }
            }

            // Здійснюємо дії з отриманими індексами, наприклад, використовуємо їх для шифрування
            if (rowIndex != -1 && colIndex != -1)
            {
                string encryptedWord = CardanoEncrypt(wordCardanoFast.Text, keyGrid.GetLength(0), rowIndex, colIndex);
                MessageBox.Show($"Зашифроване слово: {encryptedWord}");
            }
        }

        private void showMatrix_Click(object sender, EventArgs e)
        {
            // Зчитування ключа з поля keyCardano
            if (!int.TryParse(keyCardano.Text, out int size) || size <= 0)
            {
                MessageBox.Show("Будь ласка, введіть додатне ціле число для розміру матриці.");
                return;
            }

            // Видалення попередньої матриці кнопок, якщо вона існує, і створення нової
            CreateButtonMatrix(size);
        }

        private string CardanoEncrypt(string word, int size, int rowIndex, int colIndex)
        {
            List<List<char>> result = new List<List<char>>(size);

            int collector = 0;
            for (int i = 0; i < size; i++)
            {
                result.Add(new List<char>());

                for (int j = 0; j < size; j++)
                {
                    if (keyGrid[i, j])
                    {
                        if (collector < word.Length)
                        {
                            result[i].Add(word[collector]);
                            collector++;
                        }
                        else
                        {
                            result[i].Add('A'); // Заповнюємо "A", якщо в слові закінчились символи
                        }
                    }
                    else
                    {
                        result[i].Add('A');
                    }
                }
            }

            for (int rotation = 0; rotation < 3; rotation++)
            {
                keyGrid = TurnLeft(keyGrid);
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (keyGrid[i, j])
                        {
                            if (collector < word.Length)
                            {
                                result[i][j] = word[collector];
                                collector++;
                            }
                            else
                            {
                                result[i][j] = 'A'; // Заповнюємо "A", якщо в слові закінчились символи
                            }
                        }
                    }
                }
            }

            string resultEncr = "";
            foreach (List<char> innerList in result)
            {
                foreach (char character in innerList)
                {
                    resultEncr += character;
                }
            }
            return resultEncr;
        }

        private bool[,] TurnLeft(bool[,] grid)
        {
            int n = grid.GetLength(0);
            bool[,] newGrid = new bool[n, n];

            for (int j = 0; j < n; j++)
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    newGrid[j, n - 1 - i] = grid[i, j];
                }
            }

            return newGrid;
        }

        private void cardanoMenu_Click(object sender, EventArgs e)
        {
            this.Hide();
            mainMenu carM = new mainMenu();
            carM.ShowDialog();
            this.Close();
        }

        // Залиште пустими, якщо ви не плануєте використовувати ці обробники подій
        private void wordCardanoFast_TextChanged(object sender, EventArgs e) { }
        private void keyCardano_TextChanged(object sender, EventArgs e) { }
        private void cardanoEncrWord_Click(object sender, EventArgs e) { }
    }
}
