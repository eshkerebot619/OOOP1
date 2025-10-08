#pragma once
#include "Student.h"
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>

class GorshkovStarosta :
    public GorshkovStudent
{
private:
    wstring responsibility;
    int startYear;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<GorshkovStudent>(*this);
        ar& responsibility;
        ar& startYear;
    }

public:
    GorshkovStarosta();

    void SetStudent() override;
    void DisplayStudent() const override;

    void readFromFile(wifstream& inFile) override;
    void writeToFile(wofstream& outFile) const override;
};

BOOST_CLASS_EXPORT_KEY(GorshkovStarosta)
