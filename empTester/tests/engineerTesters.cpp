#include "pch.h"
#include "../fixers/engineerFixer.h"

TEST_F(engineerFixer, engineerTest) {
	EXPECT_EQ(engineer1.getId(), 1001) << "Incorrect value.";
	EXPECT_EQ(engineer1.getFirstname(), "Zeal") << "Incorrect value.";
	EXPECT_EQ(engineer1.getLastname(), "Shah") << "Incorrect value.";
	EXPECT_EQ(engineer1.getDob(), "02-02-2002") << "Incorrect value.";
	EXPECT_EQ(engineer1.getSpecialization(), "Test1") << "Incorrect value.";
}

TEST_F(engineerFixer, InsertEngineerTest) {
	EXPECT_TRUE(EmployeeController::insertEmployeeController(e1));
	EXPECT_TRUE(EngineerController::insertEngineerController(engineer1, salary1));
}

TEST_F(engineerFixer, UpdateEngineerTest) {
	EXPECT_TRUE(EngineerController::updateEngineerController(engineer2, "specialization"));
}

TEST_F(engineerFixer, DeleteEngineerTest) {
	EXPECT_TRUE(EngineerController::deleteEngineerController(engineer1, "id"));
}
