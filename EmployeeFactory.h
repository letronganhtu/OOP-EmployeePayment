#include <map>
#include <memory>
#include <iostream>
using namespace std;

#include "Employee.h"

class EmployeeFactory {
private:
    inline static shared_ptr<EmployeeFactory> _instance = NULL;
    map<int, shared_ptr<Employee>> _prototypes;

    EmployeeFactory();
public:
    static shared_ptr<EmployeeFactory> instance();

    shared_ptr<Employee> create(string, string);
};