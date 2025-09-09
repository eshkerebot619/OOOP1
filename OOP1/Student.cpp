#include "Student.h"
#include <iostream>
#include <fstream>

GorshkovStudent::GorshkovStudent() : name(""), age(0), group("") {}

GorshkovStudent::GorshkovStudent(const string& n, const int& a, const string& g) : name(n), age(a), group(g) {}

void GorshkovStudent::SetStudent()
{
	cout << "Enter name: ";
	getline(cin, name);
	

	cout << "Enter age: ";
	cin >> age;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter group: ";
	getline(cin, group);

}

void GorshkovStudent::DisplayStudent() const
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Group: " << group << endl;
	cout << "-------------------" << endl;
}

void GorshkovStudent::readFromFile(ifstream& inFile)
{
	getline(inFile, name);
	inFile >> age;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(inFile, group);
}

void GorshkovStudent::writeToFile(ofstream& outFile)
{
	outFile << name << endl;
	outFile << age << endl;
	outFile << group << endl;
}

string GorshkovStudent::GetName() const
{
	return name;
}

int GorshkovStudent::GetAge() const
{
	return age;
}

string GorshkovStudent::GetGroup() const
{
	return group;
}

