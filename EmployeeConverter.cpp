#include <sstream>

#include "EmployeeConverter.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"

string EmployeeConverter::converter(shared_ptr<Employee> buffer) {
    stringstream builder;

    if (dynamic_pointer_cast<DailyEmployee>(buffer)) {
        shared_ptr<DailyEmployee> item = dynamic_pointer_cast<DailyEmployee>(buffer);
        builder << item->dailyPayment() << " " << item->totalDays() << " " << item->name() << endl;
        builder << "=> Final payment: " << item->finalPayment() << endl;
    }
    else if (dynamic_pointer_cast<HourlyEmployee>(buffer)) {
        shared_ptr<HourlyEmployee> item = dynamic_pointer_cast<HourlyEmployee>(buffer);
        builder << item->hourlyPayment() << " " << item->totalHours() << " " << item->name() << endl;
        builder << "=> Final payment: " << item->finalPayment() << endl;
    }
    else if (dynamic_pointer_cast<ProductEmployee>(buffer)) {
        shared_ptr<ProductEmployee> item = dynamic_pointer_cast<ProductEmployee>(buffer);
        builder << item->paymentPerProduct() << " " << item->totalProducts() << " " << item->name() << endl;
        builder << "=> Final payment: " << item->finalPayment() << endl;
    }
    else if (dynamic_pointer_cast<Manager>(buffer)) {
        shared_ptr<Manager> item = dynamic_pointer_cast<Manager>(buffer);
        builder << item->fixedPayment() << " " << item->totalEmployees() << " " << item->paymentPerEmployee() << " " << item->name() << endl;
        builder << "=> Final payment: " << item->finalPayment() << endl;
    }

    string result = builder.str();
    return result;
}