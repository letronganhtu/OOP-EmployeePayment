#include <iostream>
#include <string>
#include <memory>
using namespace std;

#include "Employee.h"

class EmployeeConverter {
public:
    string converter(shared_ptr<Employee>);
};