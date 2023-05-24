#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

class KeyUser
{
    string nameUser;
    string address;
    string phoneNumber;

public:
    KeyUser() : nameUser(""), address(""), phoneNumber("") {}
    KeyUser(string name, string address, string number) : nameUser(name), address(address), phoneNumber(number) {}

    const string GetName() const { return nameUser; }
    const string GetAddres() const { return address; }
    string GetPhone() const { return phoneNumber; }

    void SetNumber(string number) { phoneNumber = number; }

    friend istream& operator >> (istream& is, KeyUser& keyUzer)
    {
        is >> keyUzer.nameUser >> keyUzer.address >> keyUzer.phoneNumber;
        return is;
    }
    friend ostream& operator << (ostream& out, const KeyUser& keyUzer)
    {
        out << keyUzer.nameUser << keyUzer.address << keyUzer.phoneNumber;
        return out;
    }
};

class PhoneModel {
private:
    string manufacturer;
    string model;
    int price;

public:
    PhoneModel() : manufacturer(""), model(""), price(0) {}
    PhoneModel(string manufacturer, string model, int price) : manufacturer(manufacturer), model(model), price(price) {}

    string GetManufacturer() const { return manufacturer; }
    string GetModel() const { return model; }
    int GetPrice() const { return price; }

    friend istream& operator >> (istream& is, PhoneModel& phone)
    {
        is >> phone.manufacturer >> phone.model >> phone.price;
        return is;
    }
    friend ostream& operator << (ostream& out, const PhoneModel& phone)
    {
        out << phone.manufacturer << phone.model << phone.price;
        return out;
    }
};

class PhoneDatabase
{
    map<KeyUser, PhoneModel> phoneDatabase;

public:
    PhoneDatabase() : phoneDatabase() {}
    PhoneDatabase(map<KeyUser, PhoneModel> PhoneDatabase) : phoneDatabase(PhoneDatabase) {}

    map<KeyUser, PhoneModel> GetPhones() const { return phoneDatabase; }

    void ReadFromFile(const string& fileName);

    void WriteToFile(const string& fileName) const;

    void addPhone(const KeyUser& owner, const PhoneModel& phone) { phoneDatabase[owner] = phone; }

    void RemovePhonesByUser(const string& name, map<KeyUser, PhoneModel>& other);

    KeyUser FindUsersByPhone(const string& phone) const;

    vector<KeyUser> FindUsersByAddress(const string& address) const;

    vector<KeyUser> FindUsersManAndPrice(const string& manufacturer, double price) const;

    int TheCostOfThePhone(const vector<PhoneModel>& phones);

    void CountOwner(const vector<KeyUser>& owners, map<string, int>& stOwners);

    void TableToFile(const string& filename, const map<string, int>& stOwners, double totalCost);
};

void PhoneDatabase:: ReadFromFile(const string& fileName)
{
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << " Фаїл( " << fileName << " ) не вдалося відкрити : " << endl;
        return;
    }
    KeyUser user;
    PhoneModel phone;

    while (file >> user >> phone)
    {
        phoneDatabase[user] = phone;
    }

    file.close();
}
void PhoneDatabase:: WriteToFile(const string& fileName) const 
{
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << " Фаїл( " << fileName <<" ) не вдалося відкрити : " <<  endl;
        return;
    }
    for (const auto& record : phoneDatabase) {
        const auto& keyUser = record.first;
        const auto& phone = record.second;

        file << keyUser.GetName() << " " << keyUser.GetAddres() << " " << keyUser.GetPhone() << " ";
        file << phone.GetManufacturer() << " " << phone.GetModel() << " " << " " << phone.GetPrice() << endl;
    }
    file.close();
}
void PhoneDatabase:: RemovePhonesByUser(const string& name, map<KeyUser, PhoneModel>& other)
{
    for (auto iterator = phoneDatabase.begin(); iterator != phoneDatabase.end();)
    {
        if (iterator->first.GetName() == name)
        {
            other[iterator->first] = iterator->second;
            iterator = phoneDatabase.erase(iterator);
        }

        else
            ++iterator;

    }
}
KeyUser PhoneDatabase:: FindUsersByPhone(const string& phone) const
{
    for (const auto& data : phoneDatabase)
    {
        if (data.first.GetPhone() == phone)
            return data.first;

    }
    return KeyUser("", "", "");
}
vector<KeyUser> PhoneDatabase:: FindUsersByAddress(const string& address) const
{
    vector<KeyUser> user;

    for (const auto& data : phoneDatabase)
    {
        if (data.first.GetAddres() == address)
            user.push_back(data.first);
    }

    return user;
}
vector<KeyUser>  PhoneDatabase:: FindUsersManAndPrice(const string& manufacturer, double price) const
{
    vector<KeyUser> user;

    for (const auto& pair : phoneDatabase)
    {
        if (pair.second.GetManufacturer() == manufacturer && pair.second.GetPrice() < price)
            user.push_back(pair.first);

    }
    return user;
}
int  PhoneDatabase:: TheCostOfThePhone(const vector<PhoneModel>& phones) 
{
    int total = 0;
    for (const auto& phone : phones)
    {
        total += phone.GetPrice();
    }
    return total;
}
void PhoneDatabase:: CountOwner(const vector<KeyUser>& owners, map<string, int>& stOwners) 
{
    for (const auto& owner : owners)
    {
        ++stOwners[owner.GetAddres()];
    }
}
void PhoneDatabase:: TableToFile(const string& filename, const map<string, int>& stOwners, double totalCost) 
{
    ofstream outfile(filename);
    if (outfile) {

        for (const auto& pair : stOwners) {
            outfile << pair.first << "," << pair.second << ","
                << totalCost << endl;
        }
        outfile.close();
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    PhoneDatabase database;

    database.addPhone(KeyUser("Ilona", "Kyiv", "09933752566"), PhoneModel("Apple", "iPhone 14", 1800));

    database.addPhone(KeyUser("Yaryko", "Ternopil", "099677145596"), PhoneModel("Apple", "iPhone 11", 700));

    database.addPhone(KeyUser("Andrii", "Kyiv", "09852563626"), PhoneModel("OnePlus", "OnePluse 10 pro", 1010));

    database.addPhone(KeyUser("Gloria", "Sevastopol", "0965496776"), PhoneModel("OnePlus", "OnePluse 11", 2000));

    database.addPhone(KeyUser("Dmytro", "Lviv", "09993686"), PhoneModel("Google", "Pixel 7 pro ", 1500));

    database.WriteToFile("Output.txt");

    vector<KeyUser> users = database.FindUsersByAddress("Kyiv");
    for (const auto& user : users)
    {
        cout << " Користувачі з Києва: " << user.GetName() << endl;
    }

    map<string, int> stOwners;
    vector<PhoneModel> allPhones;

    database.CountOwner(database.FindUsersByAddress("Kyiv"), stOwners);
    database.CountOwner(database.FindUsersByAddress("Lviv"), stOwners);
    double totalCost = database.TheCostOfThePhone(allPhones);
    database.TableToFile("OwnerStats.txt", stOwners, totalCost);

    return 0;
}