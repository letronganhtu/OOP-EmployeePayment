#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

#include "Employee.h"

class EmployeeDataReader {
private:
    string _filename;
    inline static shared_ptr<EmployeeDataReader> _instance = NULL;

    EmployeeDataReader(string);
public:
    static shared_ptr<EmployeeDataReader> instance(string);

    vector<shared_ptr<Employee>> readAll();
};