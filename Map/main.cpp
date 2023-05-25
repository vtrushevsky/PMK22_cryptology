#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Phone {
public:
    Phone() = default; 
    Phone(const string& make, const string& model, double price)
        : make_(make), model_(model), price_(price) {}

    const string& getMake() const { return make_; }
    const string& getModel() const { return model_; }
    double getPrice() const { return price_; }

private:
    string make_;
    string model_;
    double price_;
};

class Owner {
public:
    Owner(const string& name, const string& address, const string& phone)
        : name_(name), address_(address), phone_(phone) {}

    bool operator<(const Owner& other) const {
        if (name_ != other.name_) {
            return name_ < other.name_;
        }
        if (address_ != other.address_) {
            return address_ < other.address_;
        }
        return phone_ < other.phone_;
    }

    const string& getName() const { return name_; }
    const string& getAddress() const { return address_; }
    const string& getPhone() const { return phone_; }

    void setPhone(const string& phone) { phone_ = phone; }

private:
    string name_;
    string address_;
    string phone_;
};

class MobileOperator {
public:
    map<Owner, Phone> getPhones() const {
        return phones_;
    }

    void addPhone(const Owner& owner, const Phone& phone) {
        phones_[owner] = phone;
    }

    void removePhonesByOwner(const string& name, map<Owner, Phone>& other) {
        for (auto iter = phones_.begin(); iter != phones_.end();) {
            if (iter->first.getName() == name) {
                other[iter->first] = iter->second;
                iter = phones_.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    Owner findOwnerByPhone(const string& phone) const {
        for (const auto& pair : phones_) {
            if (pair.first.getPhone() == phone) {
                return pair.first;
            }
        }
        return Owner("", "", "");
    }

    vector<Owner> findOwnersByAddress(const string& address) const {
        vector<Owner> owners;
        for (const auto& pair : phones_) {
            if (pair.first.getAddress() == address) {
                owners.push_back(pair.first);
            }
        }
        return owners;
    }

    vector<Owner> findOwnersByManufacturerAndPrice(const string& manufacturer, double price) const {
        vector<Owner> owners;
        for (const auto& pair : phones_) {
            if (pair.second.getMake() == manufacturer && pair.second.getPrice() > price) {
                owners.push_back(pair.first);
            }
        }
        return owners;
    }

    void writeToDisk(const string& filename) const {
        ofstream outfile(filename);
        if (outfile) {
            for (const auto& pair : phones_) {
                outfile << pair.first.getName() << ","
                    << pair.first.getAddress() << ","
                    << pair.first.getPhone() << ","
                    << pair.second.getMake() << ","
                    << pair.second.getModel() << ","
                    << pair.second.getPrice() << endl;
            }
            outfile.close();
        }
    }


    void readFromDisk(const string& filename) {
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
                    phones_[owner] = phone;
                }
                else {
                    cerr << "Error: Invalid input line - " << line << endl;
                }
            }
            infile.close();
        }
        else {
            cerr << "Error: Unable to open file - " << filename << endl;
        }
    }  
private:
    map<Owner, Phone> phones_;
    };

void countOwnersByStreet(const vector<Owner>& owners, map<string, int>& stOwners) {
    for (const auto& owner : owners) {
        ++stOwners[owner.getAddress()];
    }
}

double totalPhoneCost(const vector<Phone>& phones) {
    double total = 0.0;
    for (const auto& phone : phones) {
        total += phone.getPrice();
    }
    return total;
}

void writeTableToDisk(const string& filename, const map<string, int>& stOwners, double totalCost) {
    ofstream outfile(filename);
    if (outfile) {
        outfile << "Street,Number of Owners,Total Cost of Phones" << endl;
        for (const auto& pair : stOwners) {
            outfile << pair.first << "," << pair.second << ","
                << totalCost << endl;
        }
        outfile.close();
    }
}

int main() {
    MobileOperator mobOp;
    // Add phones to the database
    mobOp.addPhone(Owner("John Smith", "123 Main St", "555-1234"),
        Phone("Apple", "iPhone 12", 999.99));
    mobOp.addPhone(Owner("Mary Johnson", "456 Elm St", "555-5678"),
        Phone("Samsung", "Galaxy S21", 899.99));
    mobOp.addPhone(Owner("Bob Brown", "789 Oak St", "555-2468"),
        Phone("Google", "Pixel 5", 799.99));
    mobOp.addPhone(Owner("Alice Green", "123 Main St", "555-1357"),
        Phone("Apple", "iPhone SE", 399.99));

    // Write the database to a file
    mobOp.writeToDisk("phones.txt");

    // Remove all phones owned by "John Smith" and move them to another container
    map<Owner, Phone> otherPhones;
    mobOp.removePhonesByOwner("John Smith", otherPhones);

    // Find the owner of the phone number "555-5678"
    Owner owner = mobOp.findOwnerByPhone("555-5678");
    if (owner.getName() != "") {
        cout << "Owner of 555-5678 is " << owner.getName() << endl;
    }

    // Find all owners on "123 Main St"
    vector<Owner> owners = mobOp.findOwnersByAddress("123 Main St");
    for (const auto& owner : owners) {
        cout << "Owner on 123 Main St: " << owner.getName() << endl;
    }

    // Find all owners of "Apple" phones whose price exceeds $500
    owners = mobOp.findOwnersByManufacturerAndPrice("Apple", 500.0);
    for (const auto& owner : owners) {
        cout << "Apple phone owner: " << owner.getName() << endl;
    }

    // Change the phone number for "Mary Johnson"
    owner = mobOp.findOwnerByPhone("555-5678");
    if (owner.getName() != "") {
        owner.setPhone("555-9876");
    }

    // Count the number of phone owners on each street and the total cost of phones
    map<string, int> stOwners;
    vector<Phone> allPhones;
    for (const auto& pair : mobOp.getPhones()) {
        allPhones.push_back(pair.second);
    }
    countOwnersByStreet(mobOp.findOwnersByAddress("123 Main St"), stOwners);
    countOwnersByStreet(mobOp.findOwnersByAddress("456 Elm St"), stOwners);
    countOwnersByStreet(mobOp.findOwnersByAddress("789 Oak St"), stOwners);
    double totalCost = totalPhoneCost(allPhones);

    // Write the results to a file
    writeTableToDisk("owner_stats.txt", stOwners, totalCost);

    return 0;
}