#pragma once

#include "../Salary.h"
class Salary;

class SalaryController {
public:
    static bool insertSalaryController(Salary& salary);
    static bool deleteSalaryController(Salary& salary, std::string attribute);
    static bool updateSalaryController(Salary& salary, std::string attribute);
    static bool viewSalaryController(std::string selectQuery);
    static bool incrementSalaryController(Salary& salary);
};
