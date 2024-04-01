#include "pch.h"
#include "../fixers/managerFixer.h"

TEST_F(managerFixer, managerTest) {
	EXPECT_EQ(manager1.getId(), 1001) << "Incorrect value.";
	EXPECT_EQ(manager1.getFirstname(), "Zeal") << "Incorrect value.";
	EXPECT_EQ(manager1.getLastname(), "Shah") << "Incorrect value.";
	EXPECT_EQ(manager1.getDob(), "02-02-2002") << "Incorrect value.";
	EXPECT_EQ(manager1.getManagementExperience(), 3) << "Incorrect value.";
}

TEST_F(managerFixer, InsertManagerTest) {
	EXPECT_TRUE(EmployeeController::insertEmployeeController(e1));
	EXPECT_TRUE(ManagerController::insertManagerController(manager1, salary1));
}

TEST_F(managerFixer, UpdateManagerTest) {
	EXPECT_TRUE(ManagerController::updateManagerController(manager2, "project_title"));
}

TEST_F(managerFixer, DeleteManagerTest) {
	EXPECT_TRUE(ManagerController::deleteManagerController(manager1, "id"));
}
