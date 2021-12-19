#include "EmployeeFactory.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"

EmployeeFactory::EmployeeFactory() {
    auto e1 = make_shared<DailyEmployee>();
    auto e2 = make_shared<HourlyEmployee>();
    auto e3 = make_shared<ProductEmployee>();
    auto e4 = make_shared<Manager>();

    _prototypes.insert({1, e1});
    _prototypes.insert({2, e2});
    _prototypes.insert({3, e3});
    _prototypes.insert({4, e4});
}

shared_ptr<EmployeeFactory> EmployeeFactory::instance() {
    if (_instance == NULL) {
        EmployeeFactory ef;
        _instance = make_shared<EmployeeFactory>(ef);
    }
    return _instance;
}

shared_ptr<Employee> EmployeeFactory::create(string line1, string line2) {
    int choice = -1;
    if (line1.find("DailyEmployee") != -1) choice = 1;
    else if (line1.find("HourlyEmployee") != -1) choice = 2;
    else if (line1.find("ProductEmployee") != -1) choice = 3;
    else if (line1.find("Manager") != -1) choice = 4;

    auto prototype = _prototypes[choice];
    auto result = prototype->clone();

    switch (choice) {
    case 1: {
        string name;
        int payment, days;
        name = line1.substr(line1.find(':') + 2, line1.length() - line1.find(':') - 2);
        payment = stoi(line2.substr(line2.find('=') + 1, line2.find('$') - line2.find('=') - 1));
        line2 = line2.substr(line2.find(';') + 2, line2.length() - line2.find(';') - 2);
        days = stoi(line2.substr(line2.find('=') + 1, line2.length() - line2.find('=') - 1));
        result = make_shared<DailyEmployee>(payment, days, name);
        break;
    }
    case 2: {
        string name;
        int payment, days;
        name = line1.substr(line1.find(':') + 2, line1.length() - line1.find(':') - 2);
        payment = stoi(line2.substr(line2.find('=') + 1, line2.find('$') - line2.find('=') - 1));
        line2 = line2.substr(line2.find(';') + 2, line2.length() - line2.find(';') - 2);
        days = stoi(line2.substr(line2.find('=') + 1, line2.length() - line2.find('=') - 1));
        result = make_shared<HourlyEmployee>(payment, days, name);
        break;
    }
    case 3: {
        string name;
        int payment, days;
        name = line1.substr(line1.find(':') + 2, line1.length() - line1.find(':') - 2);
        payment = stoi(line2.substr(line2.find('=') + 1, line2.find('$') - line2.find('=') - 1));
        line2 = line2.substr(line2.find(';') + 2, line2.length() - line2.find(';') - 2);
        days = stoi(line2.substr(line2.find('=') + 1, line2.length() - line2.find('=') - 1));
        result = make_shared<ProductEmployee>(payment, days, name);
        break;
    }
    case 4: {
        string name;
        int fixedPayment, totalEmployees, paymentPerEmployee;
        name = line1.substr(line1.find(':') + 2, line1.length() - line1.find(':') - 2);
        fixedPayment = stoi(line2.substr(line2.find('=') + 1, line2.find('$') - line2.find('=') - 1));
        line2 = line2.substr(line2.find(';') + 2, line2.length() - line2.find(';') - 2);
        totalEmployees = stoi(line2.substr(line2.find('=') + 1, line2.find(';') - line2.find('=') - 1));
        line2 = line2.substr(line2.find(';') + 2, line2.length() - line2.find(';') - 2);
        paymentPerEmployee = stoi(line2.substr(line2.find('=') + 1, line2.find('$') - line2.find('=') - 1));
        result = make_shared<Manager>(fixedPayment, totalEmployees, paymentPerEmployee, name);
        break;
    }
    }

    return result;
}