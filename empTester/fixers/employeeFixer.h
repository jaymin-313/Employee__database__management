#pragma once
#include<gtest/gtest.h>
#include "include/Employee.h"

class employeeFixer : public testing::Test {
protected:
    void SetUp() override {
        Database::getInstance().open("employeeTest.db");
        Database::getInstance().createTables();
    }

    Employee emp1{ 1001, "Zeal", "Shah", "02-02-2002", "1234567890", "zeal.shah@example.com",
        "wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2};

    Employee emp2{ 1001, "Zeal", "Shah", "03-05-2003", "1234567890", "zeal.shah@example.com",
        "wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2 };

};