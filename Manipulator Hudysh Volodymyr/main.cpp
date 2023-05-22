#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

//Function for printing a natural and decimal logarithm table
ostream& log_table(ostream& os) {
    os << right << setw(10) << "Number" << setw(10) << "ln(x)" << setw(10) << "ln(10x)" << endl;
    for (int i = 2; i <= 100; i++) {
        os << right << fixed << setw(10) << i << setw(10) << setprecision(5) << log(i) << setw(10) << setprecision(5) << log10(i) << endl;
    }
    return os;
}

//Function to display the feed in the center of the screen
void print_centered(const string& str) {
    int width = 80;  // ширина екрану
    int str_width = str.length();
    if (str_width >= width) {
        cout << str << endl;
    }
    else {
        int padding = (width - str_width) / 2;
        cout << setw(padding + str_width) << str << endl;
    }
}

//Real time and date system manipulator
ostream& system_time(ostream& os) {
    time_t t = time(nullptr);
    tm now_time;
    localtime_s(&now_time, &t);
    os << put_time(&now_time, "%d/%m/%y %H:%M:%S");
    return os;
}

//Manipulator for alternate reading and skipping of 10 characters
istream& read_skip(istream& is) {
    char ch;
    for (int i = 0; i < 10; i++) {
        if (is.get(ch)) {
            continue;
        }
        else {
            break;
        }
    }
    return is;
}

int main() {
    // An example of using the log_table function
    cout << "Logarithm table:" << endl << log_table << endl;

    // An example of using the print_centered function
    string message;
    cout << "Enter a message: ";
    getline(cin, message);
    print_centered(message);

    // An example of using the system_time manipulator
    cout << "Current system time: " << system_time << endl;

    // An example of using the read_skip manipulator
    cout << "Enter a string to test read_skip:" << endl;
    string input;
    cin >> read_skip >> input;
    cout << "You entered: " << input << endl;

    return 0;
}


