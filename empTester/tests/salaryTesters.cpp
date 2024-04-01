#include "pch.h"
#include "../fixers/salaryFixer.h"

TEST_F(salaryFixer, AttributeSalaryTest) {
    // Check attributes before insertion
    EXPECT_EQ(salary1.getId(), 1) << "Incorrect id before insertion.";
    EXPECT_FLOAT_EQ(salary1.getBaseSalary(), 25000.0) << "Incorrect base salary before insertion.";
    EXPECT_FLOAT_EQ(salary1.getBonus(), 10000.0) << "Incorrect bonus before insertion.";
}

TEST_F(salaryFixer, UpdateSalaryTest) {
    EXPECT_TRUE(SalaryController::updateSalaryController(salary1, "base_salary")) << "Error in updating salary.";
}

TEST_F(salaryFixer, IncrementSalaryTest) {
    EXPECT_TRUE(SalaryController::incrementSalaryController(salary1)) << "Error in incrementing salary.";
}
