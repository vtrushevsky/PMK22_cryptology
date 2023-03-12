#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

class Product {
public:
    Product(std::string country_code, double price) : country_code_(country_code), price_(price) {}

    std::string get_country_code() const {
        return country_code_;
    }

    double get_price() const {
        return price_;
    }

protected:
    std::string country_code_;
    double price_;
};

class Toy : public Product {
public:
    Toy(std::string country_code, double price, std::string name, int min_age, int max_age)
        : Product(country_code, price), name_(name), min_age_(min_age), max_age_(max_age) {}

    std::string get_name() const {
        return name_;
    }

    int get_min_age() const {
        return min_age_;
    }

    int get_max_age() const {
        return max_age_;
    }

    void print_info(bool show_country_code = false) const {
        std::cout << "Назва іграшки: " << name_ << std::endl;
        std::cout << "Оптимальний вік: " << min_age_ << " - " << max_age_ << " years" << std::endl;
        std::cout << "Ціна: " << price_;
        if (show_country_code) {
            std::cout << " (Код країни: " << country_code_ << ")";
        }
        std::cout << std::endl;
    }

private:
    std::string name_;
    int min_age_;
    int max_age_;
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
  
    std::vector<Toy> recommended_toys{
        Toy("US", 9.99, "Ведмедик", 2, 6),
        Toy("JP", 19.99, "Робот-трансформер", 5, 10),
        Toy("CN", 29.99, "Літак з пультом керування", 8, 12),
        Toy("DE", 39.99, "Конструктор", 3, 8),
        Toy("KR", 49.99, "Окуляри віртуальної реальності", 10, 16)
    };


    int min_age, max_age;
    double max_price;
    std::cout << "Увідіть вікові межі (від - до): ";
    std::cin >> min_age >> max_age;
    std::cout << "Уведіть максимальне значення ціни: ";
    std::cin >> max_price;

    // Print the list of recommended toys that match the criteria
    std::cout << "Рекомендуємо придбати для " << min_age << " - " << max_age << " років та за вказаною ціною $" << max_price << ":" << std::endl;
    for (const auto& toy : recommended_toys) {
        if (toy.get_min_age() <= max_age && toy.get_max_age() >= min_age && toy.get_price() <= max_price) {
            toy.print_info(true);
        }
    }

    return 0;
}
