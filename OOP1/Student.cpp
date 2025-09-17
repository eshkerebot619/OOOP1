#include "Student.h"
#include <iostream>
#include <fstream>

GorshkovStudent::GorshkovStudent() : age(0) {}

void GorshkovStudent::SetStudent()
{
	wcout << "Enter name: ";
	getline(wcin >> ws, name);
	

	wcout << "Enter age: ";
	wcin >> age; 
	wcin.ignore(numeric_limits<streamsize>::max(), '\n');

	wcout << "Enter group: ";
	getline(wcin, group);

}

void GorshkovStudent::DisplayStudent() const
{
	wcout << "Name: " << name << endl;
	wcout << "Age: " << age << endl;
	wcout << "Group: " << group << endl;
	wcout << "-------------------" << endl;
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

