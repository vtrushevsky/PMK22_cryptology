#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Phone {
    string manufacturer;
    double price;
};

struct Owner {
    string name;
    string phoneNumber;
    string address;
    Phone phone;
};

struct StreetStatistics {
    string street;
    int ownerCount;
    double totalValue;

    StreetStatistics() = default;
    StreetStatistics(const string& street, int ownerCount, double totalValue)
        : street(street), ownerCount(ownerCount), totalValue(totalValue) {}
};

void writeDatabaseToFile(const map<string, Owner>& database, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : database) {
            const string& key = entry.first;
            const Owner& owner = entry.second;
            file << key << " " << owner.name << " " << owner.phoneNumber << " " << owner.address << " "
                 << owner.phone.manufacturer << " " << owner.phone.price << endl;
        }
        file.close();
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}

map<string, Owner> readDatabaseFromFile(const string& filename) {
    map<string, Owner> database;
    ifstream file(filename);
    if (file.is_open()) {
        string key;
        string name;
        string phoneNumber;
        string address;
        string manufacturer;
        double price;
        while (file >> key >> name >> phoneNumber >> address >> manufacturer >> price) {
            Owner owner;
            owner.name = name;
            owner.phoneNumber = phoneNumber;
            owner.address = address;
            owner.phone.manufacturer = manufacturer;
            owner.phone.price = price;
            database[key] = owner;
        }
        file.close();
    } else {
        cout << "Error: Unable to open file for reading." << endl;
    }
    return database;
}

void movePhoneNumbers(map<string, Owner>& source, map<string, Owner>& destination, const string& phoneNumber) {
    for (auto it = source.begin(); it != source.end();) {
        const Owner& owner = it->second;
        if (owner.phoneNumber == phoneNumber) {
            destination[it->first] = owner;
            it = source.erase(it);
        } else {
            ++it;
        }
    }
}

Owner findOwnerByPhoneNumber(const map<string, Owner>& database, const string& phoneNumber) {
    for (const auto& entry : database) {
        const Owner& owner = entry.second;
        if (owner.phoneNumber == phoneNumber) {
            return owner;
        }
    }
    return Owner();  // Return empty owner if not found
}

vector<Owner> findOwnersByAddress(const map<string, Owner>& database, const string& address) {
    vector<Owner> owners;
    for (const auto& entry : database) {
        const Owner& owner = entry.second;
        if (owner.address == address) {
            owners.push_back(owner);
        }
    }
    return owners;
}

bool changePhoneNumber(map<string, Owner>& database, const string& ownerName, const string& newPhoneNumber) {
    for (auto& entry : database) {
        Owner& owner = entry.second;
        if (owner.name == ownerName) {
            owner.phoneNumber = newPhoneNumber;
            return true;
        }
    }
    return false;
}


void calculateStreetStatistics(const map<string, Owner>& database, const string& filename) {
    map<string, int> streetOwnerCount;
    map<string, double> streetTotalValue;

    for (const auto& entry : database) {
        const Owner& owner = entry.second;
        const string& street = owner.address;

        streetOwnerCount[street]++;

        streetTotalValue[street] += owner.phone.price;
    }

    ofstream statisticsFile(filename);
    if (statisticsFile.is_open()) {
        statisticsFile << "Street\t\tOwner Count\tTotal Value" << endl;

        for (const auto& entry : streetOwnerCount) {
            const string& street = entry.first;
            int ownerCount = entry.second;
            double totalValue = streetTotalValue[street];

            statisticsFile << street << "\t\t" << ownerCount << "\t\t$" << totalValue << endl;
        }

        statisticsFile.close();
        cout << "Street statistics written to file: " << filename << endl;
    } else {
        cout << "Unable to open statistics file." << endl;
    }
}


int main() {
    
    map<string, Owner> database;
    Owner owner1;
    owner1.name = "John";
    owner1.phoneNumber = "123456789";
    owner1.address = "123 Main St";
    owner1.phone.manufacturer = "Apple";
    owner1.phone.price = 999.99;
    database["001"] = owner1;
    Owner owner2;
    owner2.name = "Jane";
    owner2.phoneNumber = "987654321";
    owner2.address = "456 Elm St";
    owner2.phone.manufacturer = "Samsung";
    owner2.phone.price = 799.99;
    database["002"] = owner2;
    writeDatabaseToFile(database,"/Users/solomia/Desktop/меп34/меп34/statistics.txt");
    
    map<string, Owner> loadedDatabase = readDatabaseFromFile("/Users/solomia/Desktop/меп34/меп34/database.txt");
    
    cout << "Loaded database:" << endl;
    for (const auto& entry : loadedDatabase) {
        const string& key = entry.first;
        const Owner& owner = entry.second;
        cout << "Key: " << key << ", Name: " << owner.name << ", Phone: " << owner.phoneNumber << ", Address: " << owner.address << ", Manufacturer: " << owner.phone.manufacturer << ", Price: " << owner.phone.price << endl;
    }
    
    map<string, Owner> destinationDatabase;
    movePhoneNumbers(database, destinationDatabase, "123456789");
    
    cout << "Source database after moving:" << endl;
    for (const auto& entry : database) {
        const string& key = entry.first;
        const Owner& owner = entry.second;
        cout << "Key: " << key << ", Name: " << owner.name << ", Phone: " << owner.phoneNumber << ", Address: " << owner.address << ", Manufacturer: " << owner.phone.manufacturer << ", Price: " << owner.phone.price << endl;
    }
    
    cout << "Destination database after moving:" << endl;
    for (const auto& entry : destinationDatabase) {
        const string& key = entry.first;
        const Owner& owner = entry.second;
        cout << "Key: " << key << ", Name: " << owner.name << ", Phone: " << owner.phoneNumber << ", Address: " << owner.address << ", Manufacturer: " << owner.phone.manufacturer << ", Price: " << owner.phone.price << endl;
    }
    
    Owner foundOwner = findOwnerByPhoneNumber(loadedDatabase, "987654321");
    if (!foundOwner.name.empty()) {
        cout << "Found owner by phone number:" << endl;
        cout << "Name: " << foundOwner.name << ", Phone: " << foundOwner.phoneNumber << ", Address: " << foundOwner.address << ", Manufacturer: " << foundOwner.phone.manufacturer << ", Price: " << foundOwner.phone.price << endl;
    } else {
        cout << "Owner not found by phone number." << endl;
    }
    
    vector<Owner> ownersByAddress = findOwnersByAddress(loadedDatabase, "123 Main St");
    
    cout << "Owners found by address:" << endl;
    for (const auto& owner : ownersByAddress) {
        cout << "Name: " << owner.name << ", Phone: " << owner.phoneNumber << ", Address: " << owner.address << ", Manufacturer: " << owner.phone.manufacturer << ", Price: " << owner.phone.price << endl;
    }
    bool phoneNumberChanged = changePhoneNumber(loadedDatabase, "John", "987654321");
    if (phoneNumberChanged) {
        cout << "Phone number changed successfully." << endl;
    } else {
        cout << "Failed to change phone number." << endl;
    }
    
    string filename = "/Users/solomia/Desktop/меп34/меп34/street_statistics.txt";

       calculateStreetStatistics(database, filename);
    
    cout << "Street statistics:" << endl;
    
    
    return 0;
}


