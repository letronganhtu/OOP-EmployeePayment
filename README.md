# **Report of Project 2 - OOP: Employee payment**
## **0. Author's information**

Student's ID: 20127091

Name: Le Trong Anh Tu
## **1. Some supported classes and functions**

Class to represent what one `Employee` is

- Each `Employee` has their `name`

- We use `clone()` function for *prototype* design pattern, it is implemented in exact type of `Employee` (will be explained later)

- Function to calculate final payment for each `Employee`

``` c++
// You can see implementation in "Employee.cpp"
class Employee {
protected:
    string _name;
public:
    Employee();

    Employee(string);

    string name();

    virtual shared_ptr<Employee> clone() = 0;

    virtual long long finalPayment() = 0;
};
```

Four classes can be known as four types of `Employee` in this project - `DailyEmployee`, `HourlyEmployee`, `ProductEmployee` and `Manager`

- 4 classed I listed above are children class of `Employee` (You can see class diagram) &rarr; Implement `clone()` and `finalPayment()` clearly

- `DailyEmployee` has two attributes are daily payment and total days in one month

``` c++
// You can see implementation in "DailyEmployee.cpp"
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
```

- `HourlyEmployee` has two attributes are hourly payment and total hours in one month

``` c++
// You can see implementation in "HourlyEmployee.cpp"
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
```

- `ProductEmployee` has two attributes are payment per product and total products in one month

``` c++
// You can see implementation in "ProductEmployee.cpp"
class ProductEmployee: virtual public Employee {
private:
    int _paymentPerProduct;
    int _totalProducts;
public:
    ProductEmployee();

    ProductEmployee(int, int, string);

    int paymentPerProduct();

    int totalProducts();

    shared_ptr<Employee> clone();

    long long finalPayment();
};
```

- `Manager` has three attributes, fixed payment, total employees and payment per employee

``` c++
// You can see implementation in "Manager.cpp"
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
```

Class to create one `Employee` based on the choice from user

- Using *Factory* design pattern

- Using *Singleton* design pattern to make sure that there is only one instance in this Factory

- Using *Prototype* design pattern to clone new object

- With `create()` function, we create one object depend on data that store in 2 `string` line1 + line2 represent 2 lines of each `Employee`

``` c++
// You can see implementation in "EmployeeFactory.cpp"
class EmployeeFactory {
private:
    inline static shared_ptr<EmployeeFactory> _instance = NULL;
    map<int, shared_ptr<Employee>> _prototypes;

    EmployeeFactory();
public:
    static shared_ptr<EmployeeFactory> instance();

    shared_ptr<Employee> create(string, string);
};
```

Class to read data from `November2021.txt` into `vector<shared_ptr<Employee>>`

- Using *Singleton* design pattern to make sure that there is only one instance

- Output of `readAll()` is `vector<shared_ptr<Employee>>` contains all `Employee` in file

``` c++
// You can see implementation in EmployeeDataReader.cpp"
class EmployeeDataReader {
private:
    string _filename;
    inline static shared_ptr<EmployeeDataReader> _instance = NULL;

    EmployeeDataReader(string);
public:
    static shared_ptr<EmployeeDataReader> instance(string);

    vector<shared_ptr<Employee>> readAll();
};
```

Class to convert one `Employee` stored in `vector<shared_ptr<Employee>>` to console

- Input is any `Employee` which is used smart pointer

- Output is a `string` that convert all data into content that can be shown in console

``` c++
// You can see implementation in "EmployeeConverter.cpp"
class EmployeeConverter {
public:
    string converter(shared_ptr<Employee>);
};
```
## **2. Things that can be bonus point**
Class that convert one `integer` into a `string` that represent currency

- Input is any `integer` that you want to convert

- Output is a `string` that use `,` for thousand seperator and use `$` for currency

``` c++
// // You can see implementation in "IntegerToCurrencyUIConverter.cpp"
class IntegerToCurrencyUIConverter {
private:
    string _thousandSeparator = ",";
    string _currency = "$"; 
public:
    string convert(int);
};
```
## **3. Note**
When you run the project, you must take text file name `November2021.txt` into the same place as `*.exe`

Link video demo:

Expect grade in project 2: 10