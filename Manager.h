#include "Employee.h"

class Manager: virtual public Employee {
private:
    int _fixedPayment;
    int _totalEmployees;
    int _paymentPerEmployee;
public:
    Manager();

    Manager(int, int, int, string);

    int fixedPayment();

    int totalEmployees();

    int paymentPerEmployee();

    shared_ptr<Employee> clone();

    long long finalPayment();
};