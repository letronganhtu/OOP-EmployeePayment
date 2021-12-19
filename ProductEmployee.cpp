#include "ProductEmployee.h"

ProductEmployee::ProductEmployee() {}

ProductEmployee::ProductEmployee(int paymentPerProduct, int totalProducts, string name): Employee(name) {
    _paymentPerProduct = paymentPerProduct;
    _totalProducts = totalProducts;
}

int ProductEmployee::paymentPerProduct() { return _paymentPerProduct; }

int ProductEmployee::totalProducts() { return _totalProducts; }

shared_ptr<Employee> ProductEmployee::clone() { return make_shared<ProductEmployee>(); }

long long ProductEmployee::finalPayment() {
    return (long long)_paymentPerProduct * _totalProducts;
}