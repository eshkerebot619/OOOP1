#include "GorshkovGroup.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <codecvt>

void GorshkovGroup::addStudent()
{
	GorshkovStudent* newStudent = new GorshkovStudent();
	newStudent->SetStudent();
	Students.push_back(newStudent);
	wcout << "New student added succesfully!" << endl;
}

void GorshkovGroup::displayAllStudents()
{
	if (Students.empty()) {
		wcout << "Group empty" << endl;
	}
	else {
		for (const auto* student : Students) {
			student->DisplayStudent();
		}
	}
}

void GorshkovGroup::readFromFile(const wstring& filename)
{
	wifstream inFile(filename);
	if (!inFile) {
		wcerr << L"Error opening file" << endl;
		return;
	}
	inFile.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	
	int count = 0;
	inFile >> count;
	for (int i = 0; i < count; ++i) {
		GorshkovStudent* newStudent = new GorshkovStudent();
		newStudent->readFromFile(inFile);
		Students.push_back(newStudent);
	}

	inFile.close();
	wcout << L"Data loaded succesfully!" << endl;
}

void GorshkovGroup::writeToFile(const wstring& filename) const
{
	wofstream outFile(filename);
	if (!outFile) {
		wcerr << L"Error opening file" << endl;
		return;
	}

	outFile.imbue(locale(locale(), new codecvt_utf8<wchar_t>));

	outFile << Students.size() << std::endl;
	for (const auto* student : Students) {
		student->writeToFile(outFile);
	}
	outFile.close();
	wcout << "Data saved succesfully!" << endl;
}

void GorshkovGroup::clear()
{
	for (auto* student : Students) {
		delete student;
	}
	Students.clear();
	wcout << "Data cleaned!" << endl;
}


