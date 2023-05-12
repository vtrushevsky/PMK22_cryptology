#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

// Функція для друку таблиці натурального та десяткового логарифму чисел від 2 до 100
void printLogarithmsTable() {
    cout << right << setw(10) << "Number" << setw(10) << "Natural" << setw(10) << "Decimal" << endl;
    cout << setprecision(5) << fixed;

    for (int i = 2; i <= 100; ++i) {
        cout << setw(10) << i << setw(10) << log(i) << setw(10) << log10(i) << endl;
    }
}

// Функція для виводу стрічки в центрі екрану
void printStringInCenter(const string& str) {
    int screenWidth = 80; // ширина екрану
    int strWidth = str.length();

    int leftPadding = (screenWidth - strWidth) / 2;

    for (int i = 0; i < leftPadding; ++i) {
        cout << " ";
    }

    cout << str << endl;
}

// Маніпулятор виводу реального системного часу і дати
ostream& sysTime(ostream& os) {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    cout << put_time(localTime, "%c");
    return os;
}

// Маніпулятор для зчитування та пропуску 10 символів з вхідного потоку
istream& skipTenChars(istream& is) {
    is.ignore(10);
    return is;
}

int main() {
    // Виклик функції для друку таблиці натурального та десяткового логарифму
    printLogarithmsTable();

    cout << endl;

    // Виклик функції для виводу стрічки в центрі екрану
    printStringInCenter("Hello, world!");

    cout << endl;

    // Вивід реального системного часу та дати
    cout << "Current time: ";
    sysTime(cout);
    cout << endl;

    cout << endl;

    // Зчитування та пропуск 10 символів з вхідного потоку
    string input;
    cout << "Enter a string: ";
    cin >> skipTenChars >> input;
    cout << "Entered string after skipping 10 characters: " << input << endl;

    return 0;
}

