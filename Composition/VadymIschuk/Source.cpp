#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Структура для представлення талону
struct Talon {
    string subjectName;
    int score;
    string instructorName;
};

// Структура для представлення студента
struct Student {
    string fullName;
    string group;
    vector<Talon> talons;
};

// Функція для зчитування даних з файлу
vector<Student> readDataFromFile(const string& filename) {
    vector<Student> students;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            Student student;
            student.fullName = line;
            getline(inputFile, student.group);

            int numTalons;
            inputFile >> numTalons;
            inputFile.ignore();

            for (int i = 0; i < numTalons; i++) {
                Talon talon;
                getline(inputFile, talon.subjectName);
                inputFile >> talon.score;
                inputFile.ignore();
                getline(inputFile, talon.instructorName);
                student.talons.push_back(talon);
            }

            students.push_back(student);
        }

        inputFile.close();
    }

    return students;
}

// Функція для запису списку студентів з більш ніж одним талоном у файл
void writeStudentsWithMultipleTalons(const vector<Student>& students, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto& student : students) {
            if (student.talons.size() > 1) {
                outputFile << "Full Name: " << student.fullName << endl;
                outputFile << "Group: " << student.group << endl;
                outputFile << "Number of Talons: " << student.talons.size() << endl;

                for (const auto& talon : student.talons) {
                    outputFile << "Subject: " << talon.subjectName << endl;
                    outputFile << "Score: " << talon.score << endl;
                    outputFile << "Instructor: " << talon.instructorName << endl;
                }

                outputFile << "-----------------------" << endl;
            }
        }

        outputFile.close();
    }
}

// Функція для запису прізвища викладача з найбільшою кількістю талонів у файл
void writeInstructorWithMostTalons(const vector<Student>& students, const string& filename) {
    map<string, int> instructorCounts;

    for (const auto& student : students) {
        for (const auto& talon : student.talons) {
            instructorCounts[talon.instructorName]++;
        }
    }

    auto maxInstructor = max_element(instructorCounts.begin(), instructorCounts.end(),
        [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second < p2.second;
        }
    );

    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << "Instructor with Most Talons: " << maxInstructor->first << endl;
        outputFile << "Number of Talons: " << maxInstructor->second << endl;
        outputFile.close();
    }
}

int main() {
    string inputFilename = "input.txt";
    string outputFilename1 = "output1.txt";
    string outputFilename2 = "output2.txt";

    vector<Student> students = readDataFromFile(inputFilename);

    writeStudentsWithMultipleTalons(students, outputFilename1);
    writeInstructorWithMostTalons(students, outputFilename2);

    return 0;
}
