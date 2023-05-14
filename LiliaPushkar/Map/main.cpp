#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

class KeyOwner
{
    string name_owner;
    string address;
    string phone_number;

public:
    KeyOwner() : name_owner(""), address(""), phone_number("") {}
    KeyOwner(string n, string a, string p) : name_owner(n), address(a), phone_number(p) {}

    const string GetName() const { return name_owner; }
    const string GetAddres() const { return address; }
    string GetPhone() const { return phone_number; }

    void SetNumber(string num) { phone_number = num; }

    friend istream& operator >> (istream& is, KeyOwner& k)
    {
        is >> k.name_owner;
        is >> k.address;
        is >> k.phone_number;

        return is;
    }


    friend ostream& operator << (ostream& out, const KeyOwner& k)
    {
        out << k.name_owner;
        out << k.address;
        out << k.phone_number;

        return out;
    }
};

class ValuePhone {
private:
    string manufacturer;
    string model;
    int price;

public:
    ValuePhone() : manufacturer(""), model(""), price(0) {}
    ValuePhone(string ma, string mo, int p) : manufacturer(ma), model(mo), price(p) {}

    string GetManufacturer() const { return manufacturer; }
    string GetModel() const { return model; }

    int GetPrice() const { return price; }



    friend istream& operator >> (istream& is, ValuePhone& v)
    {
        is >> v.manufacturer;
        is >> v.model;
        is >> v.price;

        return is;
    }

    friend ostream& operator << (ostream& out, const ValuePhone& v)
    {
        out << v.manufacturer;
        out << v.model;
        out << v.price;

        return out;
    }
};

class PhoneDatabase
{
    map<KeyOwner, ValuePhone> phonedata;

public:
    PhoneDatabase() : phonedata() {}
    PhoneDatabase(map<KeyOwner, ValuePhone> p) : phonedata(p) {}

    map<KeyOwner, ValuePhone> GetPhones() const { return phonedata; }

    void ReadFromFile(const string& fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "Error opening file for reading: " << fileName << endl;
            return;
        }
        KeyOwner owner;
        ValuePhone phone;

        while (file >> owner >> phone)
        {
            phonedata[owner] = phone;
        }

        file.close();
    }

    void WriteToFile(const string& fileName) const {
        ofstream file(fileName);

        if (!file.is_open()) {
            cerr << "Error opening file for writing: " << fileName << endl;
            return;
        }

        for (const auto& record : phonedata) {
            const auto& keyowner = record.first;
            const auto& phone = record.second;

            file << keyowner.GetName() << " " << keyowner.GetAddres() << " " << keyowner.GetPhone() << " ";
            file << phone.GetManufacturer() << " " << phone.GetModel() << " " << " " << phone.GetPrice() << endl;
        }

        file.close();
    }

    void addPhone(const KeyOwner& owner, const ValuePhone& phone) { phonedata[owner] = phone; }

    void RemovePhonesByOwner(const string& name, map<KeyOwner, ValuePhone>& other)
    {
        for (auto iter = phonedata.begin(); iter != phonedata.end();)
        {
            if (iter->first.GetName() == name)
            {
                other[iter->first] = iter->second;
                iter = phonedata.erase(iter);
            }

            else
                ++iter;

        }
    }

    KeyOwner FindOwnerByPhone(const string& phone) const
    {
        for (const auto& pair : phonedata)
        {
            if (pair.first.GetPhone() == phone)
                return pair.first;

        }
        return KeyOwner("", "", "");
    }

    vector<KeyOwner> FindOwnersByAddress(const string& address) const
    {
        vector<KeyOwner> owners;

        for (const auto& pair : phonedata)
        {
            if (pair.first.GetAddres() == address)
                owners.push_back(pair.first);
        }

        return owners;
    }

    vector<KeyOwner> FindOwnersManAndPrice(const string& manufacturer, double price) const
    {
        vector<KeyOwner> owners;

        for (const auto& pair : phonedata)
        {
            if (pair.second.GetManufacturer() == manufacturer && pair.second.GetPrice() < price)
                owners.push_back(pair.first);

        }
        return owners;
    }

    int PhoneCost(const vector<ValuePhone>& phones) {
        int total = 0;

        for (const auto& phone : phones)
        {
            total += phone.GetPrice();
        }
        return total;
    }

    void CountOwner(const vector<KeyOwner>& owners, map<string, int>& stOwners) {
        for (const auto& owner : owners)
        {
            ++stOwners[owner.GetAddres()];
        }
    }

    void TableToFile(const string& filename, const map<string, int>& stOwners, double totalCost) {

        ofstream outfile(filename);
        if (outfile) {

            for (const auto& pair : stOwners) {
                outfile << pair.first << "," << pair.second << ","
                    << totalCost << endl;
            }
            outfile.close();
        }
    }


};

int main()
{
    PhoneDatabase data;


    data.addPhone(KeyOwner("Lola", "Kyiv", "09933345566"),
        ValuePhone("Apple", "iPhone 12", 800));

    data.addPhone(KeyOwner("Mychailo", "Lutsk", "099977345566"),
        ValuePhone("Apple", "iPhone 11", 700));

    data.addPhone(KeyOwner("Andrii", "Kyiv", "09852563626"),
        ValuePhone("Apple", "iPhone 10", 499));

    data.addPhone(KeyOwner("Anya", "Lytsk", "0965577676"),
        ValuePhone("Apple", "iPhone 11", 700));

    data.addPhone(KeyOwner("Yura", "Lviv", "09967666"),
        ValuePhone("Apple", "iPhone 11", 700));

    data.WriteToFile("Output.txt");



    vector<KeyOwner> owners = data.FindOwnersByAddress("Kyiv");
    for (const auto& owner : owners)
    {
        cout << "Owner on Kyiv: " << owner.GetName() << endl;
    }

    map<string, int> stOwners;
    vector<ValuePhone> allPhones;

    data.CountOwner(data.FindOwnersByAddress("Kyiv"), stOwners);
    data.CountOwner(data.FindOwnersByAddress("Lviv"), stOwners);

    double totalCost = data.PhoneCost(allPhones);


    data.TableToFile("owner_stats.txt", stOwners, totalCost);

    return 0;
}