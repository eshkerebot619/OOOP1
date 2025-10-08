#include "Student.h"
#include <iostream>
#include <fstream>

GorshkovStudent::GorshkovStudent() : age(0) {}

void GorshkovStudent::SetStudent()
{
	wcout << L"Введите имя: ";
	getline(wcin >> ws, name);
	

	wcout << L"Введите возраст: ";
	wcin >> age; 
	wcin.ignore(numeric_limits<streamsize>::max(), '\n');

	wcout << L"Введите группу: ";
	getline(wcin, group);

}

void GorshkovStudent::DisplayStudent() const
{
	wcout << L"Имя: " << name << endl;
	wcout << L"Возраст: " << age << endl;
	wcout << L"Группа: " << group << endl;
}

void GorshkovStudent::readFromFile(wifstream& inFile)
{
	getline(inFile >> ws, name);
	inFile >> age;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(inFile >> ws, group);
}

void GorshkovStudent::writeToFile(wofstream& outFile) const
{
	outFile << name << endl;
	outFile << age << endl;
	outFile << group << endl;
}

