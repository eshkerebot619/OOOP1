#include "GorshkovGroup.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>


void GorshkovGroup::addStudent()
{
	shared_ptr<GorshkovStudent> newStudent = make_shared<GorshkovStudent>();
	newStudent->SetStudent();
	Students.push_back(newStudent);
	wcout << L"Новый студент успешно добавлен!" << endl;
}

void GorshkovGroup::addStarosta()
{
	shared_ptr<GorshkovStarosta> newStarosta = make_shared<GorshkovStarosta>();
	newStarosta->SetStudent();
	Students.push_back(newStarosta);
	wcout << L"Новая староста добавлена успешно!" << endl;
}

void GorshkovGroup::displayAllStudents()
{
	if (Students.empty()) {
		wcout << L"Группа пуста" << endl;
	}
	else {
		for (const auto& student : Students) {
			student->DisplayStudent();
			wcout << endl;
		}
	}
}

void GorshkovGroup::readFromFile(const wstring& filename)
{
	clear();

	string narrowFilename = string(filename.begin(), filename.end());
	ifstream inFile(narrowFilename);
	if (!inFile) {
		wcerr << L"Ошибка открытия файла" << endl;
		return;
	}

	try {
		boost::archive::text_iarchive ia(inFile);
		ia.register_type<GorshkovStudent>();
		ia.register_type<GorshkovStarosta>();
		ia >> Students;
		wcout << L"Данные загружены!" << endl;
	}
	catch (const boost::archive::archive_exception& e) {
		wcerr << L"Ошибка при загрузке данных: " << e.what() << endl;
	}
	catch (const exception& e) {
		wcerr << L"Ошибка: " << e.what() << endl;
	}

	inFile.close();
}

void GorshkovGroup::writeToFile(const wstring& filename) const
{
	string narrowFilename = string(filename.begin(), filename.end());
	ofstream outFile(narrowFilename);
	if (!outFile) {
		wcerr << L"Ошибка открытия файла" << endl;
		return;
	}

	try {
		boost::archive::text_oarchive oa(outFile);
		oa.register_type<GorshkovStudent>();
		oa.register_type<GorshkovStarosta>();
		oa << Students;
		wcout << L"Данные сохранены!" << endl;
	}
	catch (const boost::archive::archive_exception& e) {
		wcerr << L"Ошибка при сохранении данных: " << e.what() << endl;
	}
	catch (const std::exception& e) {
		wcerr << L"Ошибка: " << e.what() << endl;
	}

	outFile.close();
}

void GorshkovGroup::clear()
{
	Students.clear();
	wcout << L"Данные очищены!" << endl;
}
