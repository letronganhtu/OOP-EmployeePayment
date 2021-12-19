#include "Employee.h"

class Employee;

class HourlyEmployee: virtual public Employee {
private:
    int _hourlyPayment;
    int _totalHours;
public:
    HourlyEmployee();

    HourlyEmployee(int, int, string);

    int hourlyPayment();

    int totalHours();

    shared_ptr<Employee> clone();

    long long finalPayment();
};