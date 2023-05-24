#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>

void print_log_table() {
    std::cout << std::setw(10) << "Number" << std::setw(10) << "Logarithm" << std::endl;
    std::cout << std::setw(23) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    for (int i = 2; i <= 100; ++i) {
        double naturalLog = std::log(i);
        double decimalLog = std::log10(i);
        std::cout << std::setw(10) << i << std::setw(10) << std::fixed << std::setprecision(5)
            << decimalLog << std::endl;
    }
}

void printCentered(const std::string& text) {
    int screenWidth = 80;
    int textWidth = text.length();
    int padding = (screenWidth - textWidth) / 2;

    std::cout << std::setw(padding + textWidth) << text << std::endl;
}

std::ostream& systemTime(std::ostream& os) {
    std::time_t currentTime;
    std::time(&currentTime);
    char dateTimeString[26];
    ctime_s(dateTimeString, sizeof(dateTimeString), &currentTime);
    dateTimeString[strlen(dateTimeString) - 1] = '\0';
    os << dateTimeString;
    return os;
}

std::istream& skipCharacters(std::istream& is) {
    char dummy[11];
    is.read(dummy, 10);

    return is;
}

int main() {
    // Завдання 1: Друк таблиці натурального та десяткового логарифму чисел
    std::cout << "Таблиця натурального та десяткового логарифму чисел від 2 до 100:\n";
    print_log_table();
    std::cout << std::endl;

    // Завдання 2: Виведення рядка в центрі екрану
    std::cout << "Введіть рядок: ";
    std::string userInput;
    std::getline(std::cin, userInput);
    std::cout << "Рядок в центрі екрану:\n";
    printCentered(userInput);
    std::cout << std::endl;

    // Завдання 3: Виведення системного часу та дати
    std::cout << "Поточна дата та час: ";
    std::cout << systemTime << std::endl;
    std::cout << std::endl;

    // Завдання 4: Зчитування та пропуск 10 символів
    std::cout << "Введіть рядок: ";
    std::cin >> skipCharacters;
    std::cout << "Пропущено 10 символів." << std::endl;

    return 0;
}
