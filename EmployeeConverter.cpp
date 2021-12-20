#include <sstream>

#include "EmployeeConverter.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"
#include "IntegerToCurrencyUIConverter.h"

string EmployeeConverter::converter(shared_ptr<Employee> buffer) {
    stringstream builder;

    IntegerToCurrencyUIConverter converter;
    if (dynamic_pointer_cast<DailyEmployee>(buffer)) {
        shared_ptr<DailyEmployee> item = dynamic_pointer_cast<DailyEmployee>(buffer);
        builder << "DailyEmployee: " << item->name() << endl;
        builder << "   " << "DailyPayment=" << converter.convert(item->dailyPayment()) << "; TotalDays=" << item->totalDays() << endl;
        builder << "   => Final payment: " << converter.convert(item->finalPayment()) << endl;
    }
    else if (dynamic_pointer_cast<HourlyEmployee>(buffer)) {
        shared_ptr<HourlyEmployee> item = dynamic_pointer_cast<HourlyEmployee>(buffer);
        builder << "HourlyEmployee: " << item->name() << endl;
        builder << "   " << "HourlyPayment=" << converter.convert(item->hourlyPayment()) << "; TotalHours=" << item->totalHours() << endl;
        builder << "   => Final payment: " << converter.convert(item->finalPayment()) << endl;
    }
    else if (dynamic_pointer_cast<ProductEmployee>(buffer)) {
        shared_ptr<ProductEmployee> item = dynamic_pointer_cast<ProductEmployee>(buffer);
        builder << "ProductEmployee: " << item->name() << endl;
        builder << "   " << "PaymentPerProduct=" << converter.convert(item->paymentPerProduct()) << "; TotalProducts=" << item->totalProducts() << endl;
        builder << "   => Final payment: " << converter.convert(item->finalPayment()) << endl;
    }
    else if (dynamic_pointer_cast<Manager>(buffer)) {
        shared_ptr<Manager> item = dynamic_pointer_cast<Manager>(buffer);
        builder << "Manager: " << item->name() << endl;
        builder << "   FixedPayment=" << converter.convert(item->fixedPayment()) << "; TotalEmployees=" << item->totalEmployees() << "; PaymentPerEmployee=" << converter.convert(item->paymentPerEmployee()) << endl;
        builder << "   => Final payment: " << converter.convert(item->finalPayment()) << endl;
    }

    string result = builder.str();
    return result;
}