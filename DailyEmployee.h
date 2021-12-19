#include "Employee.h"

class DailyEmployee: virtual public Employee {
private:
    int _dailyPayment;
    int _totalDays;
public:
    DailyEmployee();

    DailyEmployee(int, int, string);

    int dailyPayment();

    int totalDays();

    shared_ptr<Employee> clone();

    long long finalPayment();
};