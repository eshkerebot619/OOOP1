#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <locale>
#include "Student.h"
#include "GorshkovGroup.h"
#include "GorshkovStarosta.h"


using namespace std;

void DisplayMenu() {
    wcout << L"-------------------" << endl;
    wcout << L"1.Добавить студента" << endl;
    wcout << L"2.Добавить старосту" << endl;
    wcout << L"3.Отобразить всех студентов" << endl;
    wcout << L"4.Загрузить данные из файла" << endl;
    wcout << L"5.Сохранить данные в файл" << endl;
    wcout << L"6.Очистить студентов" << endl;
    wcout << L"0.Выход" << endl;
    wcout << L"Ваш выбор: ";
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
            Group.addStarosta();
            break;
        case 3:
            Group.displayAllStudents();
            break;
        case 4: {
            wstring filename;
            wcout << L"Введите название файла: ";
            getline(wcin, filename);
            Group.readFromFile(filename);
            break;
        }
        case 5: {
            wstring filename;
            wcout << L"Введите название файла:  ";
            getline(wcin, filename);
            Group.writeToFile(filename);
            break;
        }
        case 6: {
            Group.clear();
            break;
        }
        default:
            break;
        }
    } while (choice != 0);
    return 0;
}

