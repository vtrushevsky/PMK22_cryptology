#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Owner {
private:
    string name;
    string address;
    string phone;
public:
    Owner() {}
    Owner(string _name, string _address, string _phone) : name(_name), address(_address), phone(_phone) {}
    string GetName() const { return name; }
    string GetAddress() const { return address; }
    string GetPhone() const { return phone; }
    void SetPhone(const string& newPhone) { phone = newPhone; }

    bool operator<(const Owner& other) const {
        if (name != other.name) {
            return name < other.name;
        }
        if (address != other.address) {
            return address < other.address;
        }
        return phone < other.phone;
    }
};
class Phone {
private:
    string manufacturer;
    string model;
    double price;

public:
    Phone() : manufacturer(""), model(""), price(0) {}
    Phone(string _manufacturer, string _model, double _price) : manufacturer(_manufacturer), price(_price) {}
    string GetManufacturer() const { return manufacturer; }
    double GetPrice() const { return price; }
    void SetPrice(double _price) { price = _price; }
    string GetModel() const { return model; }
};
class MobileOperator {
private:

    map<Owner, Phone> phones;

public:


    void AddPhone(const Owner& owner, const Phone& phone) {
        phones[owner] = phone;
    }


    map<Owner, Phone> GetPhones() const {
        return phones;
    }


    void ReadFromFile(const string& filename, MobileOperator& mobileOperator) {
        ifstream infile(filename);

        if (infile)
        {
            string line;
            while (getline(infile, line))
            {
                vector<string> values;
                size_t start = 0, end;
                while ((end = line.find(',', start)) != string::npos)
                {
                    values.push_back(line.substr(start, end - start));
                    start = end + 1;
                }
                values.push_back(line.substr(start));

                if (values.size() == 6)
                {
                    Owner owner(values[0], values[1], values[2]);
                    Phone phone(values[3], values[4], stod(values[5]));
                    mobileOperator.AddPhone(owner, phone);
                }
                else
                {
                    cerr << "Error: Failed to open file for reading - " << line << endl;
                }
            }
            infile.close();
        }
        else {
            cerr << "Error: Unable to open file - " << filename << endl;
        }
    }

    void AddPhoneFromKeyboard(MobileOperator& mobileOperator) {
        string name, address, phone, manufacturer, model, priceStr;
        double price;

        cout << "Enter owner name: ";
        getline(cin, name);

        cout << "Enter owner address: ";
        getline(cin, address);

        cout << "Enter owner phone number: ";
        getline(cin, phone);

        cout << "Enter phone manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter phone model: ";
        getline(cin, model);

        cout << "Enter phone price: ";
        getline(cin, priceStr);
        price = stod(priceStr);

        Owner owner(name, address, phone);
        Phone phoneObj(manufacturer, model, price);

        mobileOperator.AddPhone(owner, phoneObj);

        cout << "Phone added successfully!" << endl;
    }

    map<Owner, Phone> searchPhonesByOwner(const string& name) const { 
        map<Owner, Phone> result;
        for (const auto& entry : phones) {
            const Owner& owner = entry.first;
            const Phone& phone = entry.second;
            if (owner.GetName() == name) {
                result[owner] = phone;
            }
        }
        return result;
    }

    map<Owner, Phone> searchPhonesByAddress(const string& address) const { 
        map<Owner, Phone> result;
        for (const auto& entry : phones) {
            const Owner& owner = entry.first;
            const Phone& phone = entry.second;
            if (owner.GetAddress() == address) {
                result[owner] = phone;
            }
        }
        return result;
    }

    map<Owner, Phone> searchPhonesByManufacturerAndPrice(const string& manufacturer, double price) const { 
        map<Owner, Phone> result;
        for (const auto& entry : phones) {
            const Owner& owner = entry.first;
            const Phone& phone = entry.second;
            if (phone.GetManufacturer() == manufacturer && phone.GetPrice() > price) {
                result[owner] = phone;
            }
        }
        return result;
    }

    Owner findOwnerByPhone(const string& phone) const {  
        for (const auto& pair : phones) {
            if (pair.first.GetPhone() == phone) {
                return pair.first;
            }
        }
        return Owner("", "", "");
    }

    void countOwnersByStreet(map<string, int>& result) const {
        for (const auto& entry : phones) {
            const Owner& owner = entry.first;
            const string& address = owner.GetAddress();
            size_t end = address.find_last_of(' ');
            if (end != string::npos) {
                string street = address.substr(0, end);
                result[street]++;
            }
        }
    }

    double totalPhoneValue() const {
        double totalValue = 0;
        for (const auto& entry : phones) {
            const Phone& phone = entry.second;
            totalValue += phone.GetPrice();
        }
        return totalValue;
    }


    void WriteToFile(const string& filename) const {
        ofstream outfile(filename);
        if (outfile) {
            for (const auto& pair : phones) {
                outfile << pair.first.GetName() << ","
                    << pair.first.GetAddress() << ","
                    << pair.first.GetPhone() << ","
                    << pair.second.GetManufacturer() << ","
                    << pair.second.GetModel()
                    << pair.second.GetPrice() << endl;
            }
            outfile.close();
        }
    }



    void removePhonesByOwner(const string& name, map<Owner, Phone>& other) {
        for (auto iter = phones.begin(); iter != phones.end();) {
            if (iter->first.GetName() == name) {
                other[iter->first] = iter->second;
                iter = phones.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

};
void ToFileBoard(const string& filename, const map<string, int>& stOwners, double totalCost) {
    ofstream outfile(filename);
    if (outfile) {
        outfile << "Street, Count of Owners, Total Cost of Phones" << endl;
        for (const auto& pair : stOwners) {
            outfile << pair.first << "," << pair.second << ","
                << totalCost << endl;
        }
        outfile.close();
    }
}
int main()
{
    MobileOperator mobileOp;
    // Add phones 
    mobileOp.AddPhone(Owner("Amelia Brown", "765 Alk St", "555-28375"),
        Phone("Samsung", "Galaxy A51", 599.99));
    mobileOp.AddPhone(Owner("Olivia Smith", "863 Nrp St", "555-39482"),
        Phone("Apple", "iPhone 13", 950.50));
    mobileOp.AddPhone(Owner("George Wilson", "346 Ewn St", "555-34920"),
        Phone("Apple", "iPhone 14", 999.99));
    mobileOp.AddPhone(Owner("Samuel Adamson", "765 Alk St", "555-49833"),
        Phone("Huawei", "p 50", 799.99));



    mobileOp.WriteToFile("phones.txt");

    // Remove all phones owned by "John Smith" and move them to another container
    map<Owner, Phone> otherPhones;
    mobileOp.removePhonesByOwner("John Smith", otherPhones);


    // Find all owners on "765 Alk St"
    string address = "765 Alk St";
    map<Owner, Phone> owners = mobileOp.searchPhonesByAddress(address);
    for (const auto& owner : owners) {
        cout << "Owner on 765 Alk St: " << owner.first.GetName() << endl;
    }

    // Find all owners of "Apple" phones whose price exceeds $500
    owners = mobileOp.searchPhonesByManufacturerAndPrice("Apple", 700.0);
    for (const auto& owner : owners) {
        cout << "Apple phone owner: " << owner.first.GetName() << endl;
    }

    // Find the owner of the phone number 
    Owner owner = mobileOp.findOwnerByPhone("555-34920");
    if (owner.GetName() != "") {
        cout << "Owner of 555-34920 is " << owner.GetName() << endl;
    }

    // Change the phone number 
    owner = mobileOp.findOwnerByPhone("555-39482");
    if (owner.GetName() != "") {
        owner.SetPhone("555-34063");
    }

    // Count the number of phone owners on each street 
    map<string, int> ownersByStreet;
    mobileOp.countOwnersByStreet(ownersByStreet);
    cout << "Owners by street:" << endl;
    for (const auto& entry : ownersByStreet) {
        cout << entry.first << ": " << entry.second << endl;
    }
    cout << endl;

    // total phone cost
    double totalValue = mobileOp.totalPhoneValue();
    cout << "Total phone value: " << totalValue << endl;

    ToFileBoard("Owners.txt", ownersByStreet, totalValue);

    return 0;
}