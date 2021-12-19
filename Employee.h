#ifndef employee
#define employee

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Employee {
protected:
    string _name;
public:
    Employee();

    Employee(string);

    string name();

    virtual shared_ptr<Employee> clone() = 0;

    virtual long long finalPayment() = 0;
};

#endif employee