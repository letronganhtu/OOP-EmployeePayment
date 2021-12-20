#include <iostream>
#include <string>
using namespace std;

class IntegerToCurrencyUIConverter {
private:
    string _thousandSeparator = ",";
    string _currency = "$"; 
public:
    string convert(int);
};