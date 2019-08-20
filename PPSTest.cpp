#include "stdafx.h"
#include "PPSTest.h"
#include <iostream>
#include <string>

#include <PPS/PersonPlanSystem.h>
#include <PPS/Person.h>
#include <PPS/Plan.h>

using std::cout;
using std::endl;
using std::string;

using pps::PersonPlanSystem;
using pps::Person;
using pps::Plan;
using pps::PlanStatus;

#define DELETE_NEW_SINGLE(var)          \
        {                               \
            if(nullptr != var)          \
            {                           \
                delete var;             \
                var = nullptr;          \
            }                           \
        };

PPSTest::PPSTest()
{
}


PPSTest::~PPSTest()
{
}

//int main()
//{
//    // test1:Init
//    cout << "----[Test1]----" << endl;
//    PersonPlanSystem* pps = new PersonPlanSystem();
//    pps->Init();
//
//    // test2:Add one person
//    cout << "----[Test2]----" << endl;
//    string user_name = "zhuhao";
//    Person* person = new Person(user_name);
//    pps->AddOnePerson(person);
//
//    // test3:Add second person
//    cout << "----[Test3]----" << endl;
//    string user_name_2 = "guoxin";
//    Person* person_2 = new Person(user_name_2);
//    pps->AddOnePerson(person_2);
//
//    // test4:Add same name person
//    cout << "----[Test4]----" << endl;
//    string user_name_3 = "guoxin";
//    Person* person_3 = new Person(user_name_3);
//    pps->AddOnePerson(person_3);
//    cout << pps->GetCurrentPersonNum() << endl;
//
//    // test5:Delete one person
//    cout << "----[Test5]----" << endl;
//    pps->DeleteOnePerson(person_3);
//    cout << pps->GetCurrentPersonNum() << endl;
//
//    // test6:Add user plan
//    cout << "----[Test6]----" << endl;
//    string plan_info = "20190617:Travel";
//    Plan* plan_1 = new Plan(plan_info);
//    pps->AddPersonPlan(person, plan_1);
//
//    // test7:Show user plan
//    cout << "----[Test7]----" << endl;
//    pps->ShowPersonPlan(person);
//
//    // test8:Set plan status
//    cout << "----[Test8]----" << endl;
//    PlanStatus plan_status = PlanStatus::DONE;
//    pps->SetPlanStatus(person, plan_1, plan_status);
//    pps->ShowPersonPlan(person);
//
//    // test9:Add other user plan
//    cout << "----[Test9]----" << endl;
//    string plan_info_2 = "20190507:Study";
//    Plan* plan_2 = new Plan(plan_info_2);
//    pps->AddPersonPlan(person, plan_2);
//    pps->ShowPersonPlan(person);
//
//    DELETE_NEW_SINGLE(pps);
//    DELETE_NEW_SINGLE(person);
//    DELETE_NEW_SINGLE(person_2);
//    DELETE_NEW_SINGLE(person_3);
//    DELETE_NEW_SINGLE(plan_1);
//    DELETE_NEW_SINGLE(plan_2);
//
//    system("pause");
//    return 1;
//}
