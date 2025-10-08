#pragma once
#include <vector>
#include <string>
#include <memory>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include "GorshkovStarosta.h"
#include "Student.h"

class GorshkovGroup
{
private:
	vector <shared_ptr<GorshkovStudent>> Students;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& Students;
	}

public:
	GorshkovGroup() = default;

	void addStudent();
	void addStarosta();
	void displayAllStudents();
	void readFromFile(const wstring& filename);
	void writeToFile(const wstring& filename) const;
	void clear();
};

