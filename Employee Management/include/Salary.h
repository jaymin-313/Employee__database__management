#ifndef salary_flag
#define salary_flag

#include <iostream>
#include "database.h"
#include "log.h"
#include "validate.h"
#include "attributeHelper.h"
#include "../include/controllers/salaryController.h"

class Salary {
public:

    Salary() = default;
    Salary(int id,float base ,float bonus):id(id),base_salary(base),bonus(bonus){}

    int getId() const { return id; }
    float getBaseSalary() const { return base_salary; }
    float getBonus() const { return bonus; }
    float getPercentage() const { return percentage; }

    bool setId();
    bool setBaseSalary();
    bool setBonus();
    bool setPercentage();

    Salary insertSalaryById(int id);
    bool deleteSalary();
    bool updateSalary();
    bool viewSalary();

    void describeSalary() const;

    bool incrementSalary();

    void action();

private:

    int id{};
    float percentage{};
    float base_salary {};
    float bonus{};
};

#endif