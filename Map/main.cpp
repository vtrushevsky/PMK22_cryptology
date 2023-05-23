#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Owner {
public:
    Owner(const string& name, const string& address)
        : name_(name), address_(address) {}

    void setPhoneNumber(const string& phoneNumber) {
        phoneNumber_ = phoneNumber;
    }

    string getName() const { return name_; }
    string getAddress() const { return address_; }
    string getPhoneNumber() const { return phoneNumber_; }

private:
    string name_;
    string address_;
    string phoneNumber_;
};

class Phone {
public:
    Phone(const string& model, const string& serialNumber, double price)
        : model_(model), serialNumber_(serialNumber), price_(price) {}

    string getModel() const { return model_; }
    string getSerialNumber() const { return serialNumber_; }
    double getPrice() const { return price_; }

private:
    string model_;
    string serialNumber_;
    double price_;
};

void saveDatabaseToFile(const map<Owner, Phone>& database, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : database) {
            const Owner& owner = entry.first;
            const Phone& phone = entry.second;
            file << owner.getName() << ',' << owner.getAddress() << ','
                << phone.getModel() << ',' << phone.getSerialNumber() << ',' << phone.getPrice() << '\n';
        }
        cout << "Database saved to file: " << filename << endl;
    }
    else {
        cout << "Failed to open file for writing: " << filename << endl;
    }
}

void loadDatabaseFromFile(map<Owner, Phone>& database, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        database.clear();
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name, address, model, serialNumber;
            double price;
            if (getline(iss, name, ',') && getline(iss, address, ',')
                && getline(iss, model, ',') && getline(iss, serialNumber, ',') && (iss >> price)) {
                Owner owner(name, address);
                Phone phone(model, serialNumber, price);
                database[owner] = phone;
            }
        }
        cout << "Database loaded from file: " << filename << endl;
    }
    else {
        cout << "Failed to open file for reading: " << filename << endl;
    }
}

void addToDatabaseFromInput(map<Owner, Phone>& database) {
    string name, address, model, serialNumber, phoneNumber;
    double price;
    cout << "Enter owner's name: ";
    getline(cin, name);
    cout << "Enter owner's address: ";
    getline(cin, address);
    cout << "Enter phone model: ";
    getline(cin, model);
    cout << "Enter phone serial number: ";
    getline(cin, serialNumber);
    cout << "Enter phone price: ";
    cin >> price;
    cin.ignore();
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);

    Owner owner(name, address);
    auto ownerIterator = database.find(owner);
    if (ownerIterator != database.end()) {
        cout << "Owner already exists. Do you want to change the phone number? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore();
        if (choice == 'y') {
            Owner& existingOwner = const_cast<Owner&>(ownerIterator->first);
            existingOwner.setPhoneNumber(phoneNumber);
            Phone& existingPhone = const_cast<Phone&>(ownerIterator->second);
            existingPhone = Phone(model, serialNumber, price);
            cout << "Owner and phone details updated." << endl;
        }
        else {
            cout << "Owner and phone details not updated." << endl;
        }
    }
    else {
        owner.setPhoneNumber(phoneNumber);
        Phone phone(model, serialNumber, price);
        database[owner] = phone;
        cout << "Owner and phone added to the database." << endl;
    }
}

void printDatabase(const map<Owner, Phone>& database) {
    for (const auto& entry : database) {
        const Owner& owner = entry.first;
        const Phone& phone = entry.second;
        cout << "Name: " << owner.getName() << endl;
        cout << "Address: " << owner.getAddress() << endl;
        cout << "Phone number: " << owner.getPhoneNumber() << endl;
        cout << "Model: " << phone.getModel() << endl;
        cout << "Serial number: " << phone.getSerialNumber() << endl;
        cout << "Price: " << phone.getPrice() << endl;
        cout << "------------------------" << endl;
    }
}

int main() {
    map<Owner, Phone> database;
    loadDatabaseFromFile(database, "database.txt");

    int choice;
    do {
        cout << "1. Add owner and phone to the database" << endl;
        cout << "2. Print database" << endl;
        cout << "3. Save database to file" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            addToDatabaseFromInput(database);
            break;
        case 2:
            printDatabase(database);
            break;
        case 3:
            saveDatabaseToFile(database, "database.txt");
            break;
        case 4:
            cout << "Quitting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
