#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

void setLanguage() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
}

class Owner {
public:
    Owner(const string& name, const string& address, const string& phone)
        : ownerName(name), ownerAddress(address), ownerPhone(phone) {}

    bool operator<(const Owner& other) const {
        if (ownerName != other.ownerName) {
            return ownerName < other.ownerName;
        }
        if (ownerAddress != other.ownerAddress) {
            return ownerAddress < other.ownerAddress;
        }
        return ownerPhone < other.ownerPhone;
    }

    const string& getName() const {
        return ownerName;
    }
    const string& getAddress() const {
        return ownerAddress; 
    }
    const string& getPhone() const {
        return ownerPhone; 
    }

    void setPhone(const string& phone) {
        ownerPhone = phone; 
    }

private:
    string ownerName;
    string ownerAddress;
    string ownerPhone;
};

class Phone {
public:
    Phone() = default;
    Phone(const string& manufacturer, const string& model, double price)
        : phoneManufacturer(manufacturer), phoneModel(model), phonePrice(price) {}

    const string& getManufacturer() const {
        return phoneManufacturer; 
    }
    const string& getModel() const {
        return phoneModel; 
    }
    double getPrice() const {
        return phonePrice; 
    }

private:
    string phoneManufacturer;
    string phoneModel;
    double phonePrice;
};


class MobileOperator {
public:
    map<Owner, Phone> getPhones() const {
        return phones;
    }

    void addPhone(const Owner& owner, const Phone& phone) {
        phones[owner] = phone;
    }

    void removePhonesByOwner(const string& name, map<Owner, Phone>& other) {
        for (auto iter = phones.begin(); iter != phones.end();) {
            if (iter->first.getName() == name) {
                other[iter->first] = iter->second;
                iter = phones.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    Owner findOwnerByPhone(const string& phone) const {
        for (const auto& pair : phones) {
            if (pair.first.getPhone() == phone) {
                return pair.first;
            }
        }
        return Owner("", "", "");
    }

    vector<Owner> findOwnersByAddress(const string& address) const {
        vector<Owner> owners;
        for (const auto& pair : phones) {
            if (pair.first.getAddress() == address) {
                owners.push_back(pair.first);
            }
        }
        return owners;
    }

    vector<Owner> findOwnersByManufacturerAndPrice(const string& manufacturer, double price) const {
        vector<Owner> owners;
        for (const auto& pair : phones) {
            if (pair.second.getManufacturer() == manufacturer && pair.second.getPrice() > price) {
                owners.push_back(pair.first);
            }
        }
        return owners;
    }

    void writeToDisk(const string& filename) const {
        ofstream outfile(filename);
        if (outfile) {
            for (const auto& pair : phones) {
                outfile << pair.first.getName() << ","
                    << pair.first.getAddress() << ","
                    << pair.first.getPhone() << ","
                    << pair.second.getManufacturer() << ","
                    << pair.second.getModel() << ","
                    << pair.second.getPrice() << endl;
            }
            outfile.close();
        }
    }

    void readFromDisk(const string& filename) {
        setLanguage();
        ifstream infile(filename);
        if (infile) {
            string line;
            while (getline(infile, line)) {
                vector<string> tokens;
                size_t start = 0, end;
                while ((end = line.find(',', start)) != string::npos) {
                    tokens.push_back(line.substr(start, end - start));
                    start = end + 1;
                }
                tokens.push_back(line.substr(start));

                if (tokens.size() == 6) {
                    Owner owner(tokens[0], tokens[1], tokens[2]);
                    Phone phone(tokens[3], tokens[4], stod(tokens[5]));
                    phones[owner] = phone;
                }
                else {
                    cerr << "Не правильно введено дані !" << line << endl;
                }
            }
            infile.close();
        }
    }
private:
    map<Owner, Phone> phones;
};

void countOwnersByStreet(const vector<Owner>& owners, map<string, int>& stOwners) {
    for (const auto& owner : owners) {
        ++stOwners[owner.getAddress()];
    }
}

double totalPhoneCost(const vector<Phone>& phones) {
    double totalPhonesPrice = 0.0;
    for (const auto& phone : phones) {
        totalPhonesPrice += phone.getPrice();
    }
    return totalPhonesPrice;
}

void writeTableToDisk(const string& filename, const map<string, int>& stOwners, double totalCost) {
    setLanguage();
    ofstream outfile(filename);
    if (outfile) {
        outfile << "Вулиця,Номер власника,Ціна тарифу" << endl;
        for (const auto& pair : stOwners) {
            outfile << pair.first << "," << pair.second << ","
                << totalCost << endl;
        }
        outfile.close();
    }
}

int main() {
    return 0;
}