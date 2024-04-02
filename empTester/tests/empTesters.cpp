#include "pch.h"
#include "../fixers/employeeFixer.h"
#include "include/controllers/employeeController.h"


TEST_F(employeeFixer, AttributeEmployeeTest) {
	EXPECT_EQ(emp1.getId(), 100) << "Incorrect value.";
	EXPECT_EQ(emp1.getFirstname(), "Jaymin") << "Incorrect value.";
	EXPECT_EQ(emp1.getLastname(), "Parmar") << "Incorrect value.";
	EXPECT_EQ(emp1.getDob(), "03-01-2003") << "Incorrect value.";
	EXPECT_EQ(emp1.getDoj(), "02-02-2024") << "Incorrect value.";
	EXPECT_EQ(emp1.getAddress(), "wefwefcwef") << "Incorrect value.";
	EXPECT_NE(emp1.getAddress(), "wefwefcJHGJwef");
	EXPECT_NE(emp1.getDob(), "03-04-2004");
	EXPECT_NE(emp1.getFirstname(), "name");
}

TEST_F(employeeFixer, InsertEmployeeTest) {
	EXPECT_TRUE(EmployeeController::insertEmployeeController(emp1)) << "Error department insert";
	EXPECT_FALSE(EmployeeController::insertEmployeeController(emp1));
}

TEST_F(employeeFixer, UpdateEmployeeTest) {
	EXPECT_TRUE(EmployeeController::updateEmployeeController(emp2, "dob")) << "Error department update";
	EXPECT_FALSE(EmployeeController::updateEmployeeController(emp2, "DateOfBirth"));
}

TEST_F(employeeFixer, DeleteEmployeeTest) {
	EXPECT_TRUE(EmployeeController::deleteEmployeeController(emp1, "id")) << "Error department delete";
}



