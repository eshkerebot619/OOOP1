#include "GorshkovGroup.h"
#include <iostream>
#include <fstream>

void GorshkovGroup::addStudent()
{
	GorshkovStudent* newStudent = new GorshkovStudent();
	newStudent->SetStudent();
	Students.push_back(newStudent);
	cout << "New student added succesfully!" << endl;
}

void GorshkovGroup::displayAllStudents()
{
	if (Students.empty()) {
		cout << "Group empty" << endl;
	}
	else {
		for (size_t i = 0; i < Students.size(); i++) {
			cout << "Student #" << i + 1 << ":" << endl;
			Students[i]->DisplayStudent();
		}
	}
}

void GorshkovGroup::readFromFile(const string& filename)
{
	ifstream inFile(filename);
	if (!inFile) {
		cout << "Error opening file" << endl;
		return;
	}
	while (inFile && !inFile.eof()) {
		GorshkovStudent* newStudent = new GorshkovStudent();
		newStudent->readFromFile(inFile);
		if (inFile) {
			Students.push_back(newStudent);
		}
		else {
			delete newStudent;
		}
	}

	inFile.close();
	cout << "Data loaded succesfully!" << endl;
}

void GorshkovGroup::writeToFile(const string& filename)
{
	ofstream outFile(filename);
	if (!outFile) {
		cout << "Error opening file" << endl;
		return;
	}
	for (const auto& student : Students) {
		student->writeToFile(outFile);
	}
	outFile.close();
	cout << "Data saved succesfully!" << endl;
}

void GorshkovGroup::clear()
{
	Students.clear();
	cout << "Data cleaned!" << endl;
}


