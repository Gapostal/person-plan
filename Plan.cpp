#include "stdafx.h"
#include "Plan.h"

namespace pps
{
    Plan::Plan(string content, PlanStatus plan_status)
    {
        plan_id_ = 0;
        plan_content_ = content;
        plan_status_ = plan_status;
    }

    Plan::~Plan()
    {
    }

    string Plan::GetPlanContent()
    {
        return plan_content_;
    }

    PlanStatus Plan::GetPlanStatus()
    {
        return plan_status_;
    }

    int Plan::SetPlanStatus(PlanStatus plan_status)
    {
        plan_status_ = plan_status;
        return 1;
    }

    int Plan::SetPlanID(int plan_id)
    {
        plan_id_ = plan_id;
        return 1;
    }

    int Plan::GetPlanID()
    {
        return plan_id_;
    }
}

