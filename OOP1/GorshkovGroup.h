#pragma once
#include <vector>
#include "Student.h"

class GorshkovGroup
{
private:
	vector<GorshkovStudent*> Students;
public:
	GorshkovGroup() = default;
	~GorshkovGroup() { clear(); };

	void addStudent();
	void displayAllStudents();
	void readFromFile(const string& filename);
	void writeToFile(const string& filename);
	void clear();
};

