#include <sstream>
#include <algorithm>

#include "IntegerToCurrencyUIConverter.h"

string IntegerToCurrencyUIConverter::convert(int buffer) {
    stringstream builder;

    builder << _currency;
    int count = 0;
    while (buffer != 0) {
        builder << buffer % 10;
        buffer /= 10;
        count++;
        if (count == 3 && buffer != 0) {
            count = 0;
            builder << _thousandSeparator;
        }
    }

    string result = builder.str();
    reverse(result.begin(), result.end());
    return result;
}