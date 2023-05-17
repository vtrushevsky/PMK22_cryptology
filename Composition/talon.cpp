#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Talon {
public:
    string subject_name;
    int score;
    string teacher_surname;
};

class Student {
public:
    string full_name;
    string group;
    Talon talons[10];
    int num_talons;
};

int main() {
    Student students[8];
    ifstream infile("students.txt");
    for (int i = 0; i < 8; i++) {
        infile >> students[i].full_name >> students[i].group >> students[i].num_talons;
        for (int j = 0; j < students[i].num_talons; j++) {
            infile >> students[i].talons[j].subject_name >> students[i].talons[j].score >> students[i].talons[j].teacher_surname;
        }
    }
    infile.close();

    ofstream outfile1("File1.txt");
    for (int i = 0; i < 8; i++) {
        if (students[i].num_talons > 1) {
            outfile1 << students[i].full_name << " " << students[i].group << " " << students[i].num_talons << endl;
            for (int j = 0; j < students[i].num_talons; j++) {
                outfile1 << "\t" << students[i].talons[j].subject_name << " " << students[i].talons[j].score << " " << students[i].talons[j].teacher_surname << endl;
            }
        }
    }
    outfile1.close();

    string teacher_surnames[100];
    int num_teacher_talons[100] = { 0 };
    int max_talons = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < students[i].num_talons; j++) {
            string surname = students[i].talons[j].teacher_surname;
            bool found = false;
            for (int k = 0; k < max_talons; k++) {
                if (teacher_surnames[k] == surname) {
                    num_teacher_talons[k]++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                teacher_surnames[max_talons] = surname;
                num_teacher_talons[max_talons]++;
                max_talons++;
            }
        }
    }
    int max_talons_index = 0;
    for (int i = 1; i < max_talons; i++) {
        if (num_teacher_talons[i] > num_teacher_talons[max_talons_index]) {
            max_talons_index = i;
        }
    }
    ofstream outfile2("File2.txt");
    outfile2 << teacher_surnames[max_talons_index] << endl;
    outfile2.close();

    return 0;
}
