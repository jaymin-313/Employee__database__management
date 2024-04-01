#pragma once
#include <gtest/gtest.h>
#include "include/Department.h"

class departmentFixer : public testing::Test {
protected:
    void SetUp() override {
        Database::getInstance().open("employeeTest.db");
        Database::getInstance().createTables();
    }

    Department dept1{ 10, "HR", 2, "HR Test department" };
    Department dept2{ 10, "Test", 2, "HR Test department" };
};
