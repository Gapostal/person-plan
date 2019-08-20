#pragma once
#ifndef PPS_PERSON_PLAN_SYSTEM
#define PPS_PERSON_PLAN_SYSTEM

#include <map>

#include "pps/Person.h"

using std::map;

using pps::Person;

namespace pps
{
    class PersonPlanSystem
    {
    public:
        PersonPlanSystem();
        ~PersonPlanSystem();

        int Init();

        int AddOnePerson(Person* person);

        int GetCurrentPersonNum();

        int DeleteOnePerson(Person* person);

        int AddPersonPlan(Person* person, Plan* plan);

        int ShowPersonPlan(Person* person);

        int SetPlanStatus(Person* person, Plan* plan, PlanStatus plan_status);

    private:
        int current_id_;

        map<int, Person*> person_map_;
    };

}


#endif // PPS_PERSON_PLAN_SYSTEM