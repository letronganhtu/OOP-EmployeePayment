#include "Manager.h"

Manager::Manager() {}

Manager::Manager(int fixedPayment, int totalEmployees, int paymentPerEmployee, string name): Employee(name) {
    _fixedPayment = fixedPayment;
    _totalEmployees = totalEmployees;
    _paymentPerEmployee = paymentPerEmployee;
}

int Manager::fixedPayment() { return _fixedPayment; }

int Manager::totalEmployees() { return _totalEmployees; }

int Manager::paymentPerEmployee() { return _paymentPerEmployee; }

shared_ptr<Employee> Manager::clone() { return make_shared<Manager>(); }

long long Manager::finalPayment() {
    return (long long)_totalEmployees * _paymentPerEmployee + _fixedPayment;
}