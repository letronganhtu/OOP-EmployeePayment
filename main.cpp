#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

class Employee {
private:
    string _name;
public:
    Employee() {}

    Employee(string name) { _name = name; }
public:
    string name() { return _name; }
public:
    virtual shared_ptr<Employee> clone() = 0;

    virtual long long finalPayment() = 0;
};

class DailyEmployee: virtual public Employee {
private:
    int _dailyPayment;
    int _totalDays;
public:
    DailyEmployee() {}

    DailyEmployee(int dailyPayment, int totalDays, string name): Employee(name) {
        _dailyPayment = dailyPayment;
        _totalDays = totalDays;
    }
public:
    int dailyPayment() { return _dailyPayment; }

    int totalDays() { return _totalDays; }
public:
    shared_ptr<Employee> clone() { return make_shared<DailyEmployee>(); }

    long long finalPayment() {
        return (long long)_dailyPayment * _totalDays;
    }
};

class HourlyEmployee: virtual public Employee {
private:
    int _hourlyPayment;
    int _totalHours;
public:
    HourlyEmployee() {}

    HourlyEmployee(int hourlyPayment, int totalHours, string name): Employee(name) {
        _hourlyPayment = hourlyPayment;
        _totalHours = totalHours;
    }
public:
    int hourlyPayment() { return _hourlyPayment; }

    int totalHours() { return _totalHours; }
public:
    shared_ptr<Employee> clone() { return make_shared<HourlyEmployee>(); }

    long long finalPayment() {
        return (long long)_hourlyPayment * _totalHours;
    }
};

class ProductEmployee: virtual public Employee {
private:
    int _paymentPerProduct;
    int _totalProducts;
public:
    ProductEmployee() {}

    ProductEmployee(int paymentPerProduct, int totalProducts, string name): Employee(name) {
        _paymentPerProduct = paymentPerProduct;
        _totalProducts = totalProducts;
    }
public:
    int paymentPerProduct() { return _paymentPerProduct; }

    int totalProducts() { return _totalProducts; }
public:
    shared_ptr<Employee> clone() { return make_shared<ProductEmployee>(); }

    long long finalPayment() {
        return (long long)_paymentPerProduct * _totalProducts;
    }
};

class Manager: virtual public Employee {
private:
    int _fixedPayment;
    int _totalEmployees;
    int _paymentPerEmployee;
public:
    Manager() {}

    Manager(int fixedPayment, int totalEmployees, int paymentPerEmployee, string name): Employee(name) {
        _fixedPayment = fixedPayment;
        _totalEmployees = totalEmployees;
        _paymentPerEmployee = paymentPerEmployee;
    }
public:
    int fixedPayment() { return _fixedPayment; }

    int totalEmployees() { return _totalEmployees; }

    int paymentPerEmployee() { return _paymentPerEmployee; }
public:
    shared_ptr<Employee> clone() { return make_shared<Manager>(); }

    long long finalPayment() {
        return (long long)_totalEmployees * _paymentPerEmployee + _fixedPayment;
    }
};

class EmployeeFactory {
private:
    inline static shared_ptr<EmployeeFactory> _instance = NULL;
    map<int, shared_ptr<Employee>> _prototypes;
private:
    EmployeeFactory() {
        auto e1 = make_shared<DailyEmployee>();
        auto e2 = make_shared<HourlyEmployee>();
        auto e3 = make_shared<ProductEmployee>();
        auto e4 = make_shared<Manager>();

        _prototypes.insert({1, e1});
        _prototypes.insert({2, e2});
        _prototypes.insert({3, e3});
        _prototypes.insert({4, e4});
    }
public:
    static shared_ptr<EmployeeFactory> instance() {
        if (_instance == NULL) {
            EmployeeFactory ef;
            _instance = make_shared<EmployeeFactory>(ef);
        }
        return _instance;
    }

    shared_ptr<Employee> create(string line1, string line2) {
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
};

class EmployeeDataReader {
private:
    string _filename;
    inline static shared_ptr<EmployeeDataReader> _instance = NULL;
private:
    EmployeeDataReader(string filename) {
        _filename = filename;
    }
public:
    static shared_ptr<EmployeeDataReader> instance(string filename) {
        if (_instance == NULL) {
            EmployeeDataReader edr(filename);
            _instance = make_shared<EmployeeDataReader>(edr);
        }
        return _instance;
    }
public:
    vector<shared_ptr<Employee>> readAll() {
        vector<shared_ptr<Employee>> data;
        ifstream inp(_filename);
        string line1, line2;
        shared_ptr<Employee> temp;
        auto ef = EmployeeFactory::instance();

        while(!inp.eof()) {
            getline(inp, line1);
            getline(inp, line2);
            temp = ef->create(line1, line2);
            data.push_back(temp);
        }

        inp.close();
        return data;
    }
};

int main() {
    shared_ptr<EmployeeDataReader> readEmployee = EmployeeDataReader::instance("November2021.txt");
    vector<shared_ptr<Employee>> employeeInfo = readEmployee->readAll();

    for (int i = 0; i < employeeInfo.size(); i++) {
        if (dynamic_pointer_cast<DailyEmployee>(employeeInfo[i])) {
            shared_ptr<DailyEmployee> item = dynamic_pointer_cast<DailyEmployee>(employeeInfo[i]);
            cout << item->dailyPayment() << " " << item->totalDays() << " " << item->name() << endl;
            cout << "=> Final payment: " << item->finalPayment() << endl;
        }
        else if (dynamic_pointer_cast<HourlyEmployee>(employeeInfo[i])) {
            shared_ptr<HourlyEmployee> item = dynamic_pointer_cast<HourlyEmployee>(employeeInfo[i]);
            cout << item->hourlyPayment() << " " << item->totalHours() << " " << item->name() << endl;
            cout << "=> Final payment: " << item->finalPayment() << endl;
        }
        else if (dynamic_pointer_cast<ProductEmployee>(employeeInfo[i])) {
            shared_ptr<ProductEmployee> item = dynamic_pointer_cast<ProductEmployee>(employeeInfo[i]);
            cout << item->paymentPerProduct() << " " << item->totalProducts() << " " << item->name() << endl;
            cout << "=> Final payment: " << item->finalPayment() << endl;
        }
        else if (dynamic_pointer_cast<Manager>(employeeInfo[i])) {
            shared_ptr<Manager> item = dynamic_pointer_cast<Manager>(employeeInfo[i]);
            cout << item->fixedPayment() << " " << item->totalEmployees() << " " << item->paymentPerEmployee() << " " << item->name() << endl;
            cout << "=> Final payment: " << item->finalPayment() << endl;
        }
    }

    return 0;
}