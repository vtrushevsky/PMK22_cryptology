#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Абстрактний базовий клас "телефон"
class Phone {
protected:
    string name; // назва
    string brand; // фірма
    float price; // ціна
public:
    Phone(string n, string b, float p) : name(n), brand(b), price(p) {}
    virtual ~Phone() {}
    virtual void print() = 0; // чисто віртуальна функція для виведення інформації про телефон
    float getPrice() { return price; }
};

// Похідний клас "мобільний телефон"
class MobilePhone : public Phone {
private:
    string color; // колір
    int memory; // об'єм пам'яті
public:
    MobilePhone(string n, string b, float p, string c, int m) : Phone(n, b, p), color(c), memory(m) {}
    void print() { cout << name << " (" << brand << "), color: " << color << ", memory: " << memory << " GB, price: " << price << " UAH" << endl; }
};

// Похідний клас "радіотелефон"
class RadioPhone : public Phone {
private:
    float range; // радіус дії
    bool answeringMachine; // наявність автовідповідача
public:
    RadioPhone(string n, string b, float p, float r, bool am) : Phone(n, b, p), range(r), answeringMachine(am) {}
    void print() { cout << name << " (" << brand << "), range: " << range << " km, answering machine: " << (answeringMachine ? "yes" : "no") << ", price: " << price << " UAH" << endl; }
    bool hasAnsweringMachine() { return answeringMachine; }
};

int main() {
    vector<Phone*> phones;

    // Зчитування даних з першого файлу
    ifstream fin1("phones1.txt");
    string name, brand, color;
    float price;
    int memory;
    while (fin1 >> name >> brand >> price >> color >> memory) {
        phones.push_back(new MobilePhone(name, brand, price, color, memory));
    }
    fin1.close();

    // Зчитування даних з другого файлу
    ifstream fin2("phones2.txt");
    float range;
    bool answeringMachine;
    while (fin2 >> name >> brand >> price >> range >> answeringMachine) {
        phones.push_back(new RadioPhone(name, brand, price, range, answeringMachine));
    }
    fin2.close();

    // Сортування телефонів за ціною
    sort(phones.begin(), phones.end(), [](Phone* a, Phone* b) { return a->getPrice() < b->getPrice(); });

    // Виведення інформації про всі телефони з розрахунком загальної суми
    ofstream fout1("phones_sorted.txt");
    float sum = 0;
    return 0;
}

