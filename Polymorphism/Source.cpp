#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Phone {
protected:
    string name;
    string company;
    double price;

public:
    Phone(string n, string c, double p) : name(n), company(c), price(p) {}
    virtual ~Phone() {}

    string getName() const { return name; }
    string getCompany() const { return company; }
    double getPrice() const { return price; }
    virtual void display() const = 0;
};

class MobilePhone : public Phone {
private:
    string color;
    int memoryCapacity;

public:
    MobilePhone(string n, string c, double p, string clr, int mem)
        : Phone(n, c, p), color(clr), memoryCapacity(mem) {}

    string getColor() const { return color; }
    int getMemoryCapacity() const { return memoryCapacity; }

    void display() const override {
        cout << name << " (" << company << "): " << color
            << " mobile phone with " << memoryCapacity << "GB memory, priced at $" << price << endl;
    }
};

class Radiotelephone : public Phone {
private:
    double range;
    bool answerMachine; // rename member variable

public:
    Radiotelephone(string n, string c, double p, double rng, bool ans)
        : Phone(n, c, p), range(rng), answerMachine(ans) {}

    double getRange() const { return range; }
    bool hasAnsweringMachine() const { return answerMachine; } // update function name

    void display() const override {
        cout << name << " (" << company << "): " << range << " mile range radiotelephone";
        if (answerMachine) {
            cout << " with answering machine, priced at $" << price << endl;
        }
        else {
            cout << ", priced at $" << price << endl;
        }
    }
};


int main() {
    ifstream file1("file1.txt");
    vector<Radiotelephone> radios;
    string name, company;
    double price, range;
    bool hasAnsweringMachine;
    while (file1 >> name >> company >> price >> range >> hasAnsweringMachine) {
        Radiotelephone r(name, company, price, range, hasAnsweringMachine);
        radios.push_back(r);
    }
    file1.close();

    ifstream file2("file2.txt");
    vector<MobilePhone> mobiles;
    string color;
    int memoryCapacity;
    while (file2 >> name >> company >> price >> color >> memoryCapacity) {
        MobilePhone m(name, company, price, color, memoryCapacity);
        mobiles.push_back(m);
    }
    file2.close();


    ofstream file3("file3.txt");

    vector<Phone*> allPhones;
    for (auto& r : radios) {
        allPhones.push_back(&r);
    }
    for (auto& m : mobiles) {
        allPhones.push_back(&m);
    }
    sort(allPhones.begin(), allPhones.end(), [](Phone* p1, Phone* p2) {
        return p1->getPrice() < p2->getPrice();
        });

    if (file3.is_open()) {
        for (auto p : allPhones) {
            file3 << p->getName() << " (" << p->getCompany() << "): $" << p->getPrice() << endl;
        }
    }
    else {
        cout << "Unable to open file3.txt for writing" << endl;
    }

    double totalAmount = 0;
    for (auto& p : allPhones) {
        p->display();
        totalAmount += p->getPrice();
    }
    file3 << "\nTotal amount of all phones: $" << totalAmount << endl;

    file3 << endl << "Radiotelephones with answering machines:" << endl;
    for (const auto& r : radios) {
        if (r.hasAnsweringMachine()) {
            file3 << "Name: " << r.getName() << endl;
            file3 << "Company: " << r.getCompany() << endl;
            file3 << "Price: $" << r.getPrice() << endl;
            file3 << "Range: " << r.getRange() << " km" << endl;
            file3 << "Answering Machine: Yes" << endl;
            file3 << endl;
        }
    }

    file3.close();
    return 0;
}