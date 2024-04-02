#include "pch.h"
#include "../fixers/departmentFixer.h"
#include "include/controllers/departmentController.h"

TEST_F(departmentFixer, AttributeDepartmentTest) {
    EXPECT_EQ(dept1.getId(), 10) << "Incorrect value for id.";
    EXPECT_EQ(dept1.getName(), "HR") << "Incorrect value for name.";
    EXPECT_EQ(dept1.getManagerId(), 2) << "Incorrect value for manager id.";
    EXPECT_EQ(dept1.getDescription(), "HR Test department") << "Incorrect value for description.";
    EXPECT_NE(dept1.getId(), 0);
    EXPECT_NE(dept1.getName(), "HUMAN RESOURCE");
    EXPECT_NE(dept1.getManagerId(), 7);
    EXPECT_NE(dept1.getDescription(), "HUMAN RESOURCE");
}
TEST_F(departmentFixer, InsertDepartmentTest) {
    EXPECT_TRUE(DepartmentController::insertDepartmentController(dept1)) << "Error in inserting department.";
    EXPECT_FALSE(DepartmentController::insertDepartmentController(dept1));
}

TEST_F(departmentFixer, UpdateDepartmentTest) {
    EXPECT_TRUE(DepartmentController::updateDepartmentController(dept2, "name")) << "Error in updating department.";
    EXPECT_FALSE(DepartmentController::updateDepartmentController(dept2, "name1")) << "Error in updating department.";
}

TEST_F(departmentFixer, DeleteDepartmentTest) {
    EXPECT_TRUE(DepartmentController::deleteDepartmentController(dept1, "id")) << "Error in deleting department.";
    EXPECT_FALSE(DepartmentController::deleteDepartmentController(dept1, "id1")) << "Error in deleting department.";
}