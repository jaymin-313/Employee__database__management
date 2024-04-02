#include "pch.h"
#include "../fixers/engineerFixer.h"

TEST_F(engineerFixer, engineerTest) {
	EXPECT_EQ(engineer1.getId(), 1001) << "Incorrect value.";
	EXPECT_EQ(engineer1.getFirstname(), "J") << "Incorrect value.";
	EXPECT_EQ(engineer1.getLastname(), "P") << "Incorrect value.";
	EXPECT_EQ(engineer1.getDob(), "02-02-2002") << "Incorrect value.";
	EXPECT_EQ(engineer1.getSpecialization(), "Test1") << "Incorrect value.";
	EXPECT_NE(engineer1.getId(), 101);
	EXPECT_NE(engineer1.getFirstname(), "abc");
	EXPECT_NE(engineer1.getLastname(), "xyz");
	EXPECT_NE(engineer1.getDob(), "02-02-2022");
	EXPECT_NE(engineer1.getSpecialization(), "Test");
}

TEST_F(engineerFixer, InsertEngineerTest) {
	EXPECT_TRUE(EmployeeController::insertEmployeeController(e1));
	EXPECT_FALSE(EmployeeController::insertEmployeeController(e1));
	EXPECT_TRUE(EngineerController::insertEngineerController(engineer1, salary1));
	EXPECT_FALSE(EngineerController::insertEngineerController(engineer1, salary1));
}

TEST_F(engineerFixer, UpdateEngineerTest) {
	EXPECT_TRUE(EngineerController::updateEngineerController(engineer2, "specialization"));
	EXPECT_FALSE(EngineerController::updateEngineerController(engineer2, "sp."));
}

TEST_F(engineerFixer, DeleteEngineerTest) {
	EXPECT_TRUE(EngineerController::deleteEngineerController(engineer1, "id"));
}
