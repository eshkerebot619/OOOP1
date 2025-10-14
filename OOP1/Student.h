#pragma once
#include <string>
#include <fstream>
#include <boost/serialization/string.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/shared_ptr.hpp>
using namespace std;

class GorshkovStudent
{
protected:
	wstring name;
	int age;
	wstring group;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& name;
		ar& age;
		ar& group;
	}

public:
	GorshkovStudent();
	virtual ~GorshkovStudent() = default;

	virtual void SetStudent();
	virtual void DisplayStudent() const;

};

BOOST_CLASS_EXPORT_KEY(GorshkovStudent)