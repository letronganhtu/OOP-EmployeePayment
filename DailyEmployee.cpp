#include "DailyEmployee.h"

DailyEmployee::DailyEmployee() {}

DailyEmployee::DailyEmployee(int dailyPayment, int totalDays, string name): Employee(name) {
    _dailyPayment = dailyPayment;
    _totalDays = totalDays;
}

int DailyEmployee::dailyPayment() { return _dailyPayment; }

int DailyEmployee::totalDays() { return _totalDays; }

shared_ptr<Employee> DailyEmployee::clone() { return make_shared<DailyEmployee>(); }

long long DailyEmployee::finalPayment() {
    return (long long)_dailyPayment * _totalDays;
}