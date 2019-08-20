#pragma once
#ifndef PPS_PERSON
#define PPS_PERSON

#include <string>
#include <vector>

#include "PPS/Plan.h"

using std::string;
using std::vector;

using pps::Plan;

namespace pps
{
    class Person
    {
    public:
        Person(string name);
        ~Person();

        int SetID(int id);
        int GetID();

        vector<Plan*>& GetPlan();

        string GetName();

    private:
        int id_;
        string name_;
        vector<Plan*> plan_vector_;
    };
}


#endif // PPS_PERSON