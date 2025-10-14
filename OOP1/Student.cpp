#include "Student.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <boost/serialization/export.hpp>

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

BOOST_CLASS_EXPORT_IMPLEMENT(GorshkovStudent)