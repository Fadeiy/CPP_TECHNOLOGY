#include <iostream>
#include <vector>
#include "Employee.h"
#include "CEO.h"
#include "Director.h"
#include "Secretary.h"
#include "Office.h"
#include "Department.h"
#include "Event.h"
#include "Budget.h"
#include "Cause.h"
#include "GrandDepartment.h"
#include "FundRaisingDepartment.h"
#include "Trust.h"

#include "InterfacePrint.h"
using namespace std;

void ct()
{
    cout << "\n~~~~~~~~~~~~~~~~~\n\n";
}

int main() {
    Employee emp("emp", "emp", "emp", 10, "Employee");
    emp.printDetails();
    ct();
    CEO ceo("ceo", "ceo", "ceo", 10);
    ceo.printDetails();
    ct();
    Director dir("dir", "dir", "dir", 10);
    dir.printDetails();
    ct();
    Secretary sec("sec", "sec", "sec", 10);
    sec.printDetails();
    ct();
    Office of("avenue", 2278722);
    of.printDetails();
    ct();
    Budget bud(667667);
    bud.printDetails();
    ct();
    Employee emp1("emp", "emp", "emp", 10, "Employee");
    Employee emp2("emp", "emp", "emp", 10, "CEO");
    Employee emp3("emp", "emp", "emp", 10, "Director");
    Employee emp4("emp", "emp", "emp", 10, "Secretary");
    vector<Employee> vectorOfEmployee = {emp1, emp2, emp3, emp4};
    Department dep(vectorOfEmployee, of, bud);
    dep.printDetails();
    ct();
    FundsBalance fb(667667);
    fb.printDetails();
    ct();
    Event event("YYYxxx", "Charity concert", 10000, fb);
    event.printDetails();
    ct();
    Cause cause("Petrov", "Research Article", 100000);
    cause.printDetails();
    ct();
    GrandDepartment DP(vectorOfEmployee, of, bud);
    DP.setCause(cause);
    DP.printDetails();
    DP.awardMoney(100);
    DP.track();
    DP.checkBudget();
    ct();
    FundRaisingDepartment FRD(vectorOfEmployee, of, bud);
    FRD.setEvent(event);
    FRD.checkBudget();
    event.setAmountOfMoney(110001111);
    FRD.setEvent(event);
    FRD.track();
    FRD.printDetails();
    ct();
    Trust trust(vectorOfEmployee, of, bud);
    trust.setName("Luppa");
    trust.setCEO(ceo);
    trust.setHeaderOffice(of);
    trust.setFundsBalance(fb);
    trust.printDetails();
    ct();

    //InterfacePrint print(); //Проверяем, нельзя создать экземпляр класса InterfacePrint, то есть InterfacePrint-интерфейс

    return 0;
}