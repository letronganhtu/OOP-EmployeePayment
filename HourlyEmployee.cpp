#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee() {}

HourlyEmployee::HourlyEmployee(int hourlyPayment, int totalHours, string name): Employee(name) {
    _hourlyPayment = hourlyPayment;
    _totalHours = totalHours;
}

int HourlyEmployee::hourlyPayment() { return _hourlyPayment; }

int HourlyEmployee::totalHours() { return _totalHours; }

shared_ptr<Employee> HourlyEmployee::clone() { return make_shared<HourlyEmployee>(); }

long long HourlyEmployee::finalPayment() {
    return (long long)_hourlyPayment * _totalHours;
}