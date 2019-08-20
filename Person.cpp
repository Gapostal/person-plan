#include "stdafx.h"
#include "Person.h"

namespace pps
{
    Person::Person(string name)
    {
        id_ = 0;
        name_ = name;
    }


    Person::~Person()
    {
        plan_vector_.clear();
    }

    int Person::SetID(int id)
    {
        id_ = id;
        return 1;
    }

    int Person::GetID()
    {
        return id_;
    }

    vector<Plan*>& Person::GetPlan()
    {
        return plan_vector_;
    }

    string Person::GetName()
    {
        return name_;
    }
}

