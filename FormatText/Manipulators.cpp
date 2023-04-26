#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

// Logarithm manipulator
ostream& log_table(ostream& os) {
    os << right << setw(10) << "Number" << setw(10) << "ln(x)" << setw(10) << "ln(10x)" << endl;
    for (int i = 2; i <= 100; i++) {
        os << right << fixed << setw(10) << i << setw(10) << setprecision(5) << log(i) << setw(10) << setprecision(5) << log10(i) << endl;
    }
    return os;
}

// Text centering manipulator
void center_output(const string& input) {
    int width = 80;
    int length = input.length();
    int start_pos = (width - length) / 2;
    cout << setw(start_pos + length) << input << endl;
}

// Current date and time manipulator
ostream& real(ostream& os) {
    time_t t = time(nullptr);
    tm now_time;
    localtime_s(&now_time, &t);
    os << put_time(&now_time, "%d/%m/%y %H:%M:%S");
    return os;
}

// Alternate read and skip manipulator
istream& alternate_read(istream& is) {
    char i;
    int count = 0;
    while (is.get(i)) {
        if (count % 10 == 0) {
            cout << i;
        }
        count++;
        if (count == 100) {
            break;
        }
    }
    return is;
}

int main() {
    // Logarithm manipulator
    cout << "Logarithms (natural and tenth):" << endl;
    cout << log_table << endl;

    // Text centering manipulator
    string input;
    cout << "Enter a text: ";
    getline(cin, input);
    center_output(input);

    // Current date and time manipulator
    cout << "The current date and time is: " << real << endl;

    // Alternate read and skip manipulator
    cout << "Enter a text: ";
    cin >> alternate_read >> input >> alternate_read >> input >> alternate_read;

    return 0;
}
