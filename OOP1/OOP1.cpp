#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include "Student.h"
#include "GorshkovGroup.h"
using namespace std;

void DisplayMenu() {
    wcout << "-------------------" << endl;
    wcout << "1.Add student" << endl;
    wcout << "2.Show all students" << endl;
    wcout << "3.Load students from file" << endl;
    wcout << "4.Save students into file" << endl;
    wcout << "5.Clear students" << endl;
    wcout << "0.Exit" << endl;
    wcout << "Enter your choice: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    if (_setmode(_fileno(stdout), _O_U16TEXT) == -1) {
        std::wcerr << L"Ошибка: не удалось переключить консоль в режим Unicode для вывода." << std::endl;
        return 1;
    }

    if (_setmode(_fileno(stdin), _O_U16TEXT) == -1) {
        std::wcerr << L"Ошибка: не удалось переключить консоль в режим Unicode для ввода." << std::endl;
        return 1;
    }

    int choice;
    GorshkovGroup Group;
    GorshkovStudent Student;
    do {
        DisplayMenu();
        wcin >> choice;
        wcout << endl;
        wcin.ignore();
        switch (choice)
        {
        case 1:
            Group.addStudent();
            break;
        case 2:
            Group.displayAllStudents();
            break;
        case 3: {
            wstring filename;
            wcout << L"Enter filename: ";
            getline(wcin, filename);
            Group.readFromFile(filename);
            break;
        }
        case 4: {
            wstring filename;
            wcout << L"Enter filename:  ";
            getline(wcin, filename);
            Group.writeToFile(filename);
            break;
        }
        case 5: {
            Group.clear();
            break;
        }
        default:
            break;
        }
    } while (choice != 0);
}

