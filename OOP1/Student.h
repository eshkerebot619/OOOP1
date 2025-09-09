#pragma once
#include <string>
#include <vector>
using namespace std;

class GorshkovStudent
{
private:
	string name;
	int age;
	string group;
public:
	GorshkovStudent();
	GorshkovStudent(const string& n, const int& a, const string& group);

	void SetStudent();
	void DisplayStudent() const;

	void readFromFile(ifstream& inFile);
	void writeToFile(ofstream& outFile);

	string GetName() const;
	int GetAge() const;
	string GetGroup() const;	
};

