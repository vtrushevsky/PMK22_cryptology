#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Owner {
private:
    string fullname;
    string location;
    string phoneName;
public:
    Owner() {}
    Owner(string _name, string _address, string _phone) : fullname(_name), location(_address), phoneName(_phone) {}
    string GetName() const { return fullname; }
    string GetAddress() const { return location; }
    string GetPhone() const { return phoneName; }
    void SetPhone(const string& newPhone) { phoneName = newPhone; }

    bool operator<(const Owner& other) const {
        if (fullname != other.fullname) {
            return fullname < other.fullname;
        }
        if (location != other.location) {
            return location < other.location;
        }
        return phoneName < other.phoneName;
    }
};
class Phone {
private:
    string producerName;
    string model;
    double price;

public:
    Phone() : producerName(""), model(""), price(0) {}
    Phone(string _manufacturer, string _model, double _price) : producerName(_manufacturer), price(_price) {}
    string GetManufacturer() const { return producerName; }
    double GetPrice() const { return price; }
    void SetPrice(double _price) { price = _price; }
    string GetModel() const { return model; }
};
class MobileOperator {
private:

    map<Owner, Phone> phoneModels;

public:


    void AddPhone(const Owner& owner, const Phone& phoneName) {
        phoneModels[owner] = phoneName;
    }


    map<Owner, Phone> GetPhones() const {
        return phoneModels;
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
                    Phone phoneName(values[3], values[4], stod(values[5]));
                    mobileOperator.AddPhone(owner, phoneName);
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
        string fullname, location, phoneName, producerName, model, priceStr;
        double price;

        cout << "Enter owner fullname: ";
        getline(cin, fullname);

        cout << "Enter owner location: ";
        getline(cin, location);

        cout << "Enter owner phoneName number: ";
        getline(cin, phoneName);

        cout << "Enter phoneName producerName: ";
        getline(cin, producerName);

        cout << "Enter phoneName model: ";
        getline(cin, model);

        cout << "Enter phoneName price: ";
        getline(cin, priceStr);
        price = stod(priceStr);

        Owner owner(fullname, location, phoneName);
        Phone phoneObj(producerName, model, price);

        mobileOperator.AddPhone(owner, phoneObj);

        cout << "Phone added successfully!" << endl;
    }

    map<Owner, Phone> searchPhonesByOwner(const string& fullname) const {
        map<Owner, Phone> result;
        for (const auto& entry : phoneModels) {
            const Owner& owner = entry.first;
            const Phone& phoneName = entry.second;
            if (owner.GetName() == fullname) {
                result[owner] = phoneName;
            }
        }
        return result;
    }

    map<Owner, Phone> searchPhonesByAddress(const string& location) const {
        map<Owner, Phone> result;
        for (const auto& entry : phoneModels) {
            const Owner& owner = entry.first;
            const Phone& phoneName = entry.second;
            if (owner.GetAddress() == location) {
                result[owner] = phoneName;
            }
        }
        return result;
    }

    map<Owner, Phone> searchPhonesByManufacturerAndPrice(const string& producerName, double price) const {
        map<Owner, Phone> result;
        for (const auto& entry : phoneModels) {
            const Owner& owner = entry.first;
            const Phone& phoneName = entry.second;
            if (phoneName.GetManufacturer() == producerName && phoneName.GetPrice() > price) {
                result[owner] = phoneName;
            }
        }
        return result;
    }

    Owner findOwnerByPhone(const string& phoneName) const {
        for (const auto& pair : phoneModels) {
            if (pair.first.GetPhone() == phoneName) {
                return pair.first;
            }
        }
        return Owner("", "", "");
    }

    void countOwnersByStreet(map<string, int>& result) const {
        for (const auto& entry : phoneModels) {
            const Owner& owner = entry.first;
            const string& location = owner.GetAddress();
            size_t end = location.find_last_of(' ');
            if (end != string::npos) {
                string street = location.substr(0, end);
                result[street]++;
            }
        }
    }

    double totalPhoneValue() const {
        double totalValue = 0;
        for (const auto& entry : phoneModels) {
            const Phone& phoneName = entry.second;
            totalValue += phoneName.GetPrice();
        }
        return totalValue;
    }


    void WriteToFile(const string& filename) const {
        ofstream outfile(filename);
        if (outfile) {
            for (const auto& pair : phoneModels) {
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



    void removePhonesByOwner(const string& fullname, map<Owner, Phone>& other) {
        for (auto iter = phoneModels.begin(); iter != phoneModels.end();) {
            if (iter->first.GetName() == fullname) {
                other[iter->first] = iter->second;
                iter = phoneModels.erase(iter);
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
    mobileOp.AddPhone(Owner("Amelia Brown", "765 Alk St", "555-28375"),
        Phone("Samsung", "Galaxy A51", 599.99));
    mobileOp.AddPhone(Owner("Olivia Smith", "863 Nrp St", "555-39482"),
        Phone("Apple", "iPhone 13", 950.50));
    mobileOp.AddPhone(Owner("George Wilson", "346 Ewn St", "555-34920"),
        Phone("Apple", "iPhone 14", 999.99));
    mobileOp.AddPhone(Owner("Samuel Adamson", "765 Alk St", "555-49833"),
        Phone("Huawei", "p 50", 799.99));



    mobileOp.WriteToFile("phoneModels.txt");

    map<Owner, Phone> otherPhones;
    mobileOp.removePhonesByOwner("John Smith", otherPhones);

    string location = "765 Alk St";
    map<Owner, Phone> owners = mobileOp.searchPhonesByAddress(location);
    for (const auto& owner : owners) {
        cout << "Owner on 765 Alk St: " << owner.first.GetName() << endl;
    }


    owners = mobileOp.searchPhonesByManufacturerAndPrice("Apple", 700.0);
    for (const auto& owner : owners) {
        cout << "Apple phoneName owner: " << owner.first.GetName() << endl;
    }


    Owner owner = mobileOp.findOwnerByPhone("555-34920");
    if (owner.GetName() != "") {
        cout << "Owner of 555-34920 is " << owner.GetName() << endl;
    }


    owner = mobileOp.findOwnerByPhone("555-39482");
    if (owner.GetName() != "") {
        owner.SetPhone("555-34063");
    }


    map<string, int> ownersByStreet;
    mobileOp.countOwnersByStreet(ownersByStreet);
    cout << "Owners by street:" << endl;
    for (const auto& entry : ownersByStreet) {
        cout << entry.first << ": " << entry.second << endl;
    }
    cout << endl;

    double totalValue = mobileOp.totalPhoneValue();
    cout << "Total phoneName value: " << totalValue << endl;

    ToFileBoard("Owners.txt", ownersByStreet, totalValue);

    return 0;
}