#pragma once
#include <vector>
#include <string>
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
	void readFromFile(const wstring& filename);
	void writeToFile(const wstring& filename) const;
	void clear();
};

