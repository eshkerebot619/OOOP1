#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Student.h"
#include "GorshkovGroup.h"
using namespace std;

void DisplayMenu() {
    cout << "-------------------" << endl;
    cout << "1.Add student" << endl;
    cout << "2.Show all students" << endl;
    cout << "3.Load students from file" << endl;
    cout << "4.Save students into file" << endl;
    cout << "5.Clear students" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    int choice;
    GorshkovGroup Group;
    GorshkovStudent Student;
    do {
        DisplayMenu();
        cin >> choice;
        cout << endl;
        cin.ignore();
        switch (choice)
        {
        case 1:
            Group.addStudent();
            break;
        case 2:
            Group.displayAllStudents();
            break;
        case 3: {
            string filename;
            cout << "Enter filename: ";
            getline(cin, filename);
            Group.readFromFile(filename);
            break;
        }
        case 4: {
            string filename;
            cout << "Enter filename: ";
            getline(cin, filename);
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

