#include "stdafx.h"
#include <iostream>
#include "PersonPlanSystem.h"

using std::cout;
using std::endl;

namespace pps
{
    PersonPlanSystem::PersonPlanSystem() :
        current_id_(0)
    {
    }


    PersonPlanSystem::~PersonPlanSystem()
    {
        person_map_.erase(person_map_.begin(), person_map_.end());
    }

    int PersonPlanSystem::Init()
    {
        cout << "[Info]: Enter PersonPlanSystem::Init." << endl;

        current_id_ = 0;
        person_map_.erase(person_map_.begin(), person_map_.end());

        return 1;
    }

    int PersonPlanSystem::AddOnePerson(Person * person)
    {
        cout << "[Info]: Enter PersonPlanSystem::AddOnePerson." << endl;

        if (nullptr != person)
        {
            person_map_[current_id_] = person;
            person->SetID(current_id_);
            current_id_++;
        }
        else
        {
            cout << "[Warnning]: person is not exist." << endl;
            return 0;
        }

        return 1;
    }

    int PersonPlanSystem::GetCurrentPersonNum()
    {
        return person_map_.size();
    }

    int PersonPlanSystem::DeleteOnePerson(Person * person)
    {
        cout << "[Info]: Enter PersonPlanSystem::DeleteOnePerson." << endl;

        if (nullptr != person)
        {
            person_map_.erase(person->GetID());
        }
        else
        {
            cout << "[Warnning]: person is not exist." << endl;
            return 0;
        }

        return 1;
    }

    int PersonPlanSystem::AddPersonPlan(Person * person, Plan * plan)
    {
        cout << "[Info]: Enter PersonPlanSystem::AddPersonPlan." << endl;

        if (nullptr == person)
        {
            cout << "[Warnning]: person is not exist." << endl;
            return 0;
        }

        if (nullptr == plan)
        {
            cout << "[Warnning]: plan is not exist." << endl;
            return 0;
        }

        // set plan_id = plan_vector.size()
        plan->SetPlanID(person->GetPlan().size());
        person->GetPlan().push_back(plan);

        return 1;
    }

    string PlanStatus2String(PlanStatus plan_status)
    {
        switch (plan_status)
        {
        case UNDO:
            return "UNDO";
        case DOING:
            return "DOING";
        case DONE:
            return "DONE";
        case ABAND:
            return "ABAND";
        default:
            cout << "[Warnning]: plan status is not UNDO/DOING/DONE/ABAND, will set UNDO" << endl;
            return "UNDO";
        }
    }

    int PersonPlanSystem::ShowPersonPlan(Person * person)
    {
        cout << "[Info]: Enter PersonPlanSystem::ShowPersonPlan." << endl;

        if (nullptr == person)
        {
            cout << "[Warnning]: person is not exist." << endl;
            return 0;
        }

        vector<Plan*> plan_vector = person->GetPlan();
        cout << "##############################" << endl;
        cout << "#         " << person->GetName() << endl;
        for (unsigned int i = 0; i < plan_vector.size(); ++i)
        {
            string plan_status = PlanStatus2String(plan_vector[i]->GetPlanStatus());
            cout << "#[PLAN" << i + 1 << "]:" << plan_vector[i]->GetPlanContent() << "          " << plan_status << endl;
        }
        cout << "##############################" << endl;

        return 1;
    }

    int PersonPlanSystem::SetPlanStatus(Person * person, Plan * plan, PlanStatus plan_status)
    {
        cout << "[Info]: Enter PersonPlanSystem::SetPlanStatus." << endl;

        if (nullptr == person)
        {
            cout << "[Warnning]: person is not exist." << endl;
            return 0;
        }

        if (nullptr == plan)
        {
            cout << "[Warnning]: plan is not exist." << endl;
            return 0;
        }

        for (unsigned int i = 0; i < person->GetPlan().size(); ++i)
        {
            if (person->GetPlan()[i]->GetPlanID() == plan->GetPlanID())
            {
                person->GetPlan()[i]->SetPlanStatus(plan_status);
                return 1;
            }
        }

        cout << "[Warnning]: plan is not exist." << endl;
        return 0;
    }
}

