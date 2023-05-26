#include <iostream>
#include <vector>
using namespace std;

// Базовий клас для опису інформації про товар
class Product {
protected:
    string countryOfOrigin;
    double price;
public:
    Product(const string& country, double price)
        : countryOfOrigin(country), price(price) {}

    void displayCountry() const {
        cout << "Код країни-виробника: " << countryOfOrigin << endl;
    }

    double getPrice() const {
        return price;
    }
};

// Клас "іграшка", що успадковує базовий клас "товар"
class Toy : public Product {
private:
    string name;
    int minAge;
    int maxAge;
public:
    Toy(const string& country, double price, const string& toyName, int min, int max)
        : Product(country, price), name(toyName), minAge(min), maxAge(max) {}

    void displayToyInfo() const {
        cout << "Іграшка: " << name << endl;
        cout << "Рекомендований віковий діапазон: " << minAge << " - " << maxAge << " років" << endl;
        displayCountry();
    }

    bool isInRange(int age) const {
        return (age >= minAge && age <= maxAge);
    }
};

int main() {
    // Створення переліку іграшок
    vector<Toy> toys;
    toys.push_back(Toy("UA", 10.99, "М'яч", 3, 8));
    toys.push_back(Toy("CN", 25.50, "Конструктор", 5, 12));
    toys.push_back(Toy("US", 17.75, "Лялька", 4, 10));
    toys.push_back(Toy("PL", 8.99, "Кубики", 2, 6));
    toys.push_back(Toy("UA", 12.99, "Машинка", 3, 7));

    // Запит користувача щодо вікового діапазону та цінових меж
    int minAge, maxAge;
    double minPrice, maxPrice;
    cout << "Введіть мінімальний вік: ";
    cin >> minAge;
    cout << "Введіть максимальний вік: ";
    cin >> maxAge;
    cout << "Введіть мінімальну ціну: ";
    cin >> minPrice;
    cout << "Введіть максимальну ціну: ";
    cin >> maxPrice;

    // Пошук та виведення іграшок, які задовольняють віковий діапазон та цінові межі
    cout << "Рекомендовані іграшки: " << endl;
    for (const Toy& toy : toys) {
        if (toy.isInRange(minAge) && toy.isInRange(maxAge) && toy.getPrice() >= minPrice && toy.getPrice() <= maxPrice) {
            toy.displayToyInfo();
            cout << "---------------" << endl;
        }
    }

    return 0;
}
