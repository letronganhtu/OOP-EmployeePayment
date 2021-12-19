#include "Employee.h"

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