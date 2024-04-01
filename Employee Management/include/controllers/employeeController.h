#pragma once

#include "../Employee.h"
class Employee;

class EmployeeController {
public:
    static bool insertEmployeeController(Employee& dept);
    static bool deleteEmployeeController(Employee& dept, std::string attribute);
    static bool updateEmployeeController(Employee& dept, std::string attribute);
    static bool viewEmployeeController(Employee& dept, std::string attribute);
};