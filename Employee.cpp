#include "Employee.h"

Employee::Employee() {}

Employee::Employee(string name) { _name = name; }

string Employee::name() { return _name; }