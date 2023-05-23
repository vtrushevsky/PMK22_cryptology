#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;
// Функція для виводу рядка в центрі екрану
void printCentered(const string& str) {
    int screenWidth = 80; // ширина екрану (можна змінити на бажану)
    int strWidth = str.length();
    int padding = (screenWidth - strWidth) / 2;

    cout << string(padding, ' ') << str << endl;
}

// Функція для виводу таблиці натурального та десяткового логарифму
void printLogTable() {
    cout << right << setw(10) << "Number" << setw(10) << "Log" << setw(10) << "Log10" << endl;

    for (int i = 2; i <= 100; ++i) {
        double logValue = log(i);
        double log10Value = log10(i);

        cout << right << setw(10) << i << setw(10) << fixed << setprecision(5) << logValue
            << setw(10) << fixed << setprecision(5) << log10Value << endl;
    }
}

int main() {
    // Вивід таблиці натурального та десяткового логарифму
    printLogTable();

    // Вивід рядка в центрі екрану
    string userInput;
    cout << "Введіть рядок: ";
    getline(cin, userInput);

    printCentered(userInput);

    // Вивід системного часу та дати
    time_t currentTime = time(nullptr);
    cout << "Поточний час та дата: " << asctime(localtime(&currentTime));

    // Зчитування та пропуск 10 символів зі вхідного потоку
    cout << "Введіть рядок для зчитування та пропуску 10 символів: ";
    string inputString;
    getline(cin, inputString);

    for (int i = 0; i < 10; ++i) {
        if (!inputString.empty()) {
            inputString = inputString.substr(1);
        }
    }

    cout << "Результат: " << inputString << endl;

    return 0;
}
