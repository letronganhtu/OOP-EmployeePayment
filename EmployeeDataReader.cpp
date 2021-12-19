#include <fstream>

#include "EmployeeDataReader.h"
#include "EmployeeFactory.h"

EmployeeDataReader::EmployeeDataReader(string filename) {
    _filename = filename;
}

shared_ptr<EmployeeDataReader> EmployeeDataReader::instance(string filename) {
    if (_instance == NULL) {
        EmployeeDataReader edr(filename);
        _instance = make_shared<EmployeeDataReader>(edr);
    }
    return _instance;
}

vector<shared_ptr<Employee>> EmployeeDataReader::readAll() {
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