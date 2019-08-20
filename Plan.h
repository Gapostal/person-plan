#pragma once
#ifndef PPS_PLAN
#define PPS_PLAN

#include <string>

using std::string;

namespace pps
{
    enum PlanStatus
    {
        UNDO = 0,
        DOING,
        DONE,
        ABAND,
    };

    class Plan
    {
    public:
        Plan(string content, PlanStatus plan_status = UNDO);
        ~Plan();

        string GetPlanContent();

        PlanStatus GetPlanStatus();
        int SetPlanStatus(PlanStatus plan_status);

        int SetPlanID(int plan_id);
        int GetPlanID();

    private:
        int plan_id_;
        string plan_content_;
        PlanStatus plan_status_;
    };
}


#endif // PPS_PLAN