#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string manufacturer_country;
    double price;

public:
    Product(string country, double price) {
        manufacturer_country = country;
        this->price = price;
    }

    string getCountryCode() {
        return manufacturer_country;
    }

    double getPrice() {
        return price;
    }
};

class Toy : public Product {
private:
    string name;
    int min_age;
    int max_age;

public:
    Toy(string country, double price, string name, int min_age, int max_age) : Product(country, price) {
        this->name = name;
        this->min_age = min_age;
        this->max_age = max_age;
    }

    string getName() {
        return name;
    }

    int getMinAge() {
        return min_age;
    }

    int getMaxAge() {
        return max_age;
    }
};

int main() {
    Toy toys[4] = {
        Toy("US", 9.99, "Lego", 5, 12),
        Toy("US", 14.99, "Barbie", 3, 8),
        Toy("CN", 7.50, "Rubik's Cube", 8, 99),
        Toy("CN", 6.99, "Yoyo", 6, 12)
    };

    cout << "Enter the minimum age for toys: ";
    int min_age;
    cin >> min_age;

    cout << "Enter the maximum age for toys: ";
    int max_age;
    cin >> max_age;

    cout << "Enter the minimum price for toys: ";
    double min_price;
    cin >> min_price;

    cout << "Enter the maximum price for toys: ";
    double max_price;
    cin >> max_price;

    cout << endl << "List of recommended toys: " << endl;

    for (int i = 0; i < 4; i++) {
        Toy toy = toys[i];
        if (toy.getMinAge() >= min_age && toy.getMaxAge() <= max_age && toy.getPrice() >= min_price && toy.getPrice() <= max_price) {
            cout << "- " << toy.getName() << " (recommended for ages " << toy.getMinAge() << " - " << toy.getMaxAge() << ", priced at $" << toy.getPrice() << ")" << endl;
        }
    }

    cout << endl << "Would you like to view a product's country code? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y') {
        cout << "Enter the name of the toy: ";
        string toy_name;
        cin >> toy_name;

        for (int i = 0; i < 4; i++) {
            Toy toy = toys[i];
            if (toy.getName() == toy_name) {
                cout << "The country code for " << toy.getName() << " is " << toy.getCountryCode() << endl;
                break;
            }
            if (i == 3) {
                cout << "Toy not found." << endl;
            }
        }
    }

    return 0;
}