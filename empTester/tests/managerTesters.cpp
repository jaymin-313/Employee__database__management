#include "pch.h"
#include "../fixers/managerFixer.h"

TEST_F(managerFixer, managerTest) {
	EXPECT_EQ(manager1.getId(), 1001) << "Incorrect value.";
	EXPECT_EQ(manager1.getFirstname(), "J") << "Incorrect value.";
	EXPECT_EQ(manager1.getLastname(), "P") << "Incorrect value.";
	EXPECT_EQ(manager1.getDob(), "02-02-2002") << "Incorrect value.";
	EXPECT_EQ(manager1.getManagementExperience(), 3) << "Incorrect value.";
	EXPECT_NE(manager1.getId(), 101);
	EXPECT_NE(manager1.getFirstname(), "abc");
	EXPECT_NE(manager1.getLastname(), "xyz");
	EXPECT_NE(manager1.getDob(), "02-02-2022");
	EXPECT_NE(manager1.getManagementExperience(), 8);
}

TEST_F(managerFixer, InsertManagerTest) {
	EXPECT_TRUE(EmployeeController::insertEmployeeController(e1));
	EXPECT_FALSE(EmployeeController::insertEmployeeController(e1));
	EXPECT_TRUE(ManagerController::insertManagerController(manager1, salary1));
}

TEST_F(managerFixer, UpdateManagerTest) {
	EXPECT_TRUE(ManagerController::updateManagerController(manager2, "project_title"));
	EXPECT_FALSE(ManagerController::updateManagerController(manager2, "project title"));
}

TEST_F(managerFixer, DeleteManagerTest) {
	EXPECT_TRUE(ManagerController::deleteManagerController(manager1, "id"));
}
