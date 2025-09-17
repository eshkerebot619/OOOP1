#pragma once
#include <string>
#include <fstream>
using namespace std;

class GorshkovStudent
{
private:
	wstring name;
	int age;
	wstring group;
public:
	GorshkovStudent();

	void SetStudent();
	void DisplayStudent() const;

	void readFromFile(wifstream& inFile);
	void writeToFile(wofstream& outFile) const;
};

