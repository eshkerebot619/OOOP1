#include "GorshkovStarosta.h"
#include <iostream>
#include <string>
#include <boost/serialization/export.hpp>

GorshkovStarosta::GorshkovStarosta() : startYear(0) {}

void GorshkovStarosta::SetStudent()
{
	GorshkovStudent::SetStudent();

	wcout << L"Введите обязаности: ";
	getline(wcin >> ws, responsibility);

	wcout << L"Введите год начала срока: ";
	wcin >> startYear;
	wcin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void GorshkovStarosta::DisplayStudent() const
{
	GorshkovStudent::DisplayStudent();
	wcout << L"Обязанности: " << responsibility << endl;
	wcout << L"Год начала срока: " << startYear << endl;
	wcout << endl;
}

void GorshkovStarosta::readFromFile(wifstream& inFile)
{
	GorshkovStudent::readFromFile(inFile);
	getline(inFile >> ws, responsibility);
	inFile >> startYear;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
}

void GorshkovStarosta::writeToFile(wofstream& outFile) const
{
	GorshkovStudent::writeToFile(outFile);
	outFile << responsibility << endl;
	outFile << startYear << endl;
}




