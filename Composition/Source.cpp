#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Define the struct for Talon and student
struct Talon {
    string subject;
    int semesterScores;
    string teacherLastName;
};

struct Student {
    string firstName;
    string lastName;
    string patronymic;
    string group;
    vector<Talon> Talons;
    int numberOfTalons;
};

// Read data from file
void readDataFromFile(vector<Student>& students, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file " << fileName << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        // Split line into fields
        vector<string> fields;
        size_t startPos = 0;
        size_t endPos = line.find(',');
        while (endPos != string::npos) {
            fields.push_back(line.substr(startPos, endPos - startPos));
            startPos = endPos + 1;
            endPos = line.find(',', startPos);
        }
        fields.push_back(line.substr(startPos));

        // Create a student object and add to the vector
        Student student;
        student.firstName = fields[0];
        student.lastName = fields[1];
        student.patronymic = fields[2];
        student.group = fields[3];
        student.numberOfTalons = stoi(fields[4]);
        for (size_t i = 5; i < fields.size(); i += 3) {
            Talon Talon;
            Talon.subject = fields[i];
            Talon.semesterScores = stoi(fields[i + 1]);
            Talon.teacherLastName = fields[i + 2];
            student.Talons.push_back(Talon);
        }
        students.push_back(student);
    }
    file.close();
}

// Check if a student has more than one Talon
bool hasMultipleTalons(const Student& student) {
    return student.Talons.size() > 1;
}

// Find the name of the teacher who appears in the largest number of coupons
string findTeacherNameWithMostCoupons(const vector<Student>& students) {
    map<string, int> teacherCouponCounts;
    for (const auto& student : students) {
        for (const auto& Talon : student.Talons) {
            teacherCouponCounts[Talon.teacherLastName]++;
        }
    }
    auto maxElement = max_element(
        teacherCouponCounts.begin(),
        teacherCouponCounts.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; }
    );
    return maxElement->first;
}

// Write the result to file
void writeResultToFile(const vector<Student>& students, const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file " << fileName << endl;
        return;
    }
    for (const auto& student : students) {
        if (hasMultipleTalons(student)) {
            file << student.firstName << " " << student.lastName << " " << student.patronymic << endl;
        }
    }
    file << findTeacherNameWithMostCoupons(students) << endl;
    file.close();
}

int main() {
    vector<Student> students;
    readDataFromFile(students, "students.txt");
    writeResultToFile(students, "result.txt");
    return 0;
}
