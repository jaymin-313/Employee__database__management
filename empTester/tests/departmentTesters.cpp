#include "pch.h"
#include "../fixers/departmentFixer.h"
#include "include/controllers/departmentController.h"

TEST_F(departmentFixer, AttributeDepartmentTest) {
    EXPECT_EQ(dept1.getId(), 10) << "Incorrect value for id.";
    EXPECT_EQ(dept1.getName(), "HR") << "Incorrect value for name.";
    EXPECT_EQ(dept1.getManagerId(), 2) << "Incorrect value for manager id.";
    EXPECT_EQ(dept1.getDescription(), "HR Test department") << "Incorrect value for description.";
}
TEST_F(departmentFixer, InsertDepartmentTest) {
    EXPECT_TRUE(DepartmentController::insertDepartmentController(dept1)) << "Error in inserting department.";
}

TEST_F(departmentFixer, UpdateDepartmentTest) {
    EXPECT_TRUE(DepartmentController::updateDepartmentController(dept2, "name")) << "Error in updating department.";
}

TEST_F(departmentFixer, DeleteDepartmentTest) {
    EXPECT_TRUE(DepartmentController::deleteDepartmentController(dept1, "id")) << "Error in deleting department.";
}