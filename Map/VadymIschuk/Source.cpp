
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

const string FILE_PATH = "C:\\Users\\888\\Desktop\\phonesContainer.txt";
const string FILE_PATH_RESULT = "C:\\Users\\888\\Desktop\\result.txt";

class Owner {
public:
    string name;
    string address;

    Owner()
    {
    }

    Owner(const string& name, const string& address)
        : name(name), address(address) {}

    bool operator<(const Owner& other) const {
        if (name != other.name)
            return name < other.name;
        return address < other.address;
    }

    string ToString() {
        return "\tName: " + name + " Address: " + address + "\n";
    }
};

class Phone {
public:
    string model;
    double price;
    string phoneNumber;

    Phone() {}

    Phone(const string& model, double price, const string& phoneNumber)
        : model(model), price(price), phoneNumber(phoneNumber) {}

    string ToString() {
        return "\tModel: " + model + " Price: " + to_string(price) + " Phone number: " + phoneNumber + "\n";
    }
};

using PhoneDatabase = map<Owner, Phone>;



void loadDatabaseFromFile(PhoneDatabase& database) {
    ifstream file(FILE_PATH, ios::app);

    if (!file) {
        cout << "Error file opening!" << endl;
        return;
    }

    database.clear();

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string name, address, model, number;
        double price;
        getline(iss, name, ',');
        getline(iss, address, ',');
        getline(iss, model, ',');
        getline(iss, number, ',');
        iss >> price;

        if (!name.empty())
        {
            Owner owner(name, address);
            Phone phone(model, price, number);
            database.emplace(move(owner), move(phone));
        }
    }

    file.close();
}

void saveDatabaseToFile(PhoneDatabase& database, const string& filename) {
    ofstream file(filename, ios::app);

    if (!file) {
        cout << "Error file opening!" << endl;
        return;
    }

    for (const auto& pair : database) {
        const Owner& owner = pair.first;
        const Phone& phone = pair.second;
        file << owner.name << ',' << owner.address << ',' << phone.model << ',' << phone.phoneNumber << ',' << phone.price << endl;
    }

    file.close();
}

void addRecordFromInput() {
    string name, address, model, number;
    double price;

    cout << "Enter owner name: ";
    getline(cin, name);

    cout << "Enter owner address: ";
    getline(cin, address);

    cout << "Enter phone model: ";
    getline(cin, model);

    cout << "Enter phone number: ";
    getline(cin, number);

    cout << "Enter phone price: ";
    cin >> price;

    Owner owner(name, address);
    Phone phone(model, price, number);

    PhoneDatabase database;
    database[owner] = phone;

    saveDatabaseToFile(database, FILE_PATH);
}

void showAllEntries()
{
    PhoneDatabase database;
    loadDatabaseFromFile(database);

    for (const auto& pair : database) {
        const Owner& owner = pair.first;
        const Phone& phone = pair.second;

        cout << "\tName: " + owner.name + " Address: " + owner.address + "\n";
        cout << "\tModel: " + phone.model + " Price: " + to_string(phone.price) + " Phone number: " + phone.phoneNumber + "\n";
        cout << endl;
    }
}

void showUsersByAddress(string address)
{
    PhoneDatabase database;
    loadDatabaseFromFile(database);

    cout << "\t\tUsers by following address: " + address << endl << endl;
    for (const auto& pair : database) {
        const Owner& owner = pair.first;
        const Phone& phone = pair.second;

        if (owner.address == address) {
            cout << "\tName: " + owner.name + " Address: " + owner.address + "\n";
            cout << "\tModel: " + phone.model + " Price: " + to_string(phone.price) + " Phone number: " + phone.phoneNumber + "\n";
            cout << endl;
        }
    }
}

void showUsersByPhoneNumber(string number)
{
    PhoneDatabase database;
    loadDatabaseFromFile(database);

  
        cout << "\t\tUsers by following phone number: " + number << endl << endl;
    for (const auto& pair : database) {
        const Owner& owner = pair.first;
        const Phone& phone = pair.second;

        if (phone.phoneNumber == number) {
            cout << "\tName: " + owner.name + " Address: " + owner.address + "\n";
            cout << "\tModel: " + phone.model + " Price: " + to_string(phone.price) + " Phone number: " + phone.phoneNumber + "\n";
            cout << endl;
        }
    }
}

void saveStatisticsToFile() {
    map<string, int> streetOwnersCount;
    map<string, double> streetPhonesValue;

    PhoneDatabase db;
    loadDatabaseFromFile(db);

    // Calculate statistics
    for (const auto& pair : db) {
        const Owner& owner = pair.first;
        const Phone& phone = pair.second;
        string street = owner.address;

        // Increment owner count on the street
        streetOwnersCount[street]++;

        // Accumulate phone value on the street
        streetPhonesValue[street] += phone.price;
    }

    ofstream file(FILE_PATH_RESULT);

    if (!file) {
        cout << "Error file opening." << endl;
        return;
    }

    // Write statistics to file
    file << "Address\tOwners count\tPhones price sum" << endl;

    for (const auto& pair : streetOwnersCount) {
        const string& street = pair.first;
        int ownersCount = pair.second;
        double phonesValue = streetPhonesValue[street];

        file << street << "\t" << ownersCount << "\t\t\t" << phonesValue << endl;
    }

    file.close();

    cout << "Statistic is saved to a file:  " << FILE_PATH_RESULT << endl;
}


int main()
{
    int answer = 0;

    while (true)
    {
        system("cls");
        cout << "\t\t Welcome to the phones DB!" << endl << endl;
        cout << "\t Show all Owners/Prones - 1" << endl;
        cout << "\t Add owner and the phone to DB - 2" << endl;
        cout << "\t Print users by Address - 3" << endl;
        cout << "\t Print users by Number - 4" << endl;
        cout << "\t Save statistics to a file - 5" << endl;
        cin >> answer;

        switch (answer)
        {
        case 1:
        {
            system("cls");
            showAllEntries();

            //sleep
            chrono::seconds duration(10);
            this_thread::sleep_for(duration);
            break;
        }
        case 2:
        {
            system("cls");
            addRecordFromInput();

            //sleep
            chrono::seconds duration(10);
            this_thread::sleep_for(duration);
            break;
        }
        case 3:
        {
            cin.ignore();
            system("cls");
            string phoneNumber;
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);

            showUsersByAddress(phoneNumber);

            //sleep
            chrono::seconds duration(10);
            this_thread::sleep_for(duration);
            break;
        }
        case 4:
        {
            cin.ignore();
            system("cls");
            string address;
            cout << "Enter phone number: ";
            getline(cin, address);

            showUsersByPhoneNumber(address);

            //sleep
            chrono::seconds duration(10);
            this_thread::sleep_for(duration);
            break;
        }
        case 5:
        {
            cin.ignore();
            system("cls");
            saveStatisticsToFile();

            //sleep
            chrono::seconds duration(10);
            this_thread::sleep_for(duration);
            break;
        }
        default:
            break;
        }

    }


    PhoneDatabase db;
    loadDatabaseFromFile(db);
    //addRecordFromInput();

    return 0;
}