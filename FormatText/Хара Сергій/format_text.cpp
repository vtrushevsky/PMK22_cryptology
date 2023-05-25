#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <ctime>
#include <sstream>
using namespace std;
// Task #1
ostream& skipCharacterByValue(ostream& os, int value)
{
    for (int i = 0; i < value; i++)
    {
        os << " ";
    }
    return os;
}
void printLogarithm()
{
    skipCharacterByValue(cout, 90);
    cout << "Nat. Log" << " ";
    cout << "10t. Log" << endl;
    skipCharacterByValue(cout, 90);
    cout << "-------------------------" << endl;
    for (int i = 2; i < 100; i++)
    {
        skipCharacterByValue(cout, 90);
        cout << "|    " << setprecision(5) << log(i) << "  |";
        cout << setprecision(5) << log10(i) << "    |" << endl;
        skipCharacterByValue(cout, 90);
        cout << "-------------------------" << endl;
    }
}
//  Task #2
void printCentered()
{
    wstring text = L"";
    getline(wcin, text);
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;

    COORD cursorPos;
    cursorPos.X = (consoleWidth - text.length()) / 2;
    cursorPos.Y = consoleHeight / 2;
    SetConsoleCursorPosition(consoleHandle, cursorPos);

    wcout << text << endl;
}
// Task #3
wostream& systemTimeAndDate(wostream& os)
{
    time_t currentTime;
    tm localTime;
    time(&currentTime);

    localtime_s(&localTime, &currentTime);

    wstringstream wss;
    wss << L"Current system time and date: " << put_time(&localTime, L"%Y-%m-%d %H:%M:%S");

    os << wss.str();

    return os;
}
// Task 4
istream& skipCharacters(istream& is)
{
    for (int i = 0; i < 10; ++i)
    {
        if (!is.get())
            break;
    }
    return is;
}
int main()
{   
    return 0;
}