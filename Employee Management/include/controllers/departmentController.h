#pragma once

#include "../Department.h"
class Department;

class DepartmentController {
public:
    static bool insertDepartmentController(Department& dept);
    static bool deleteDepartmentController(Department& dept, std::string attribute);
    static bool updateDepartmentController(Department& dept, std::string attribute);
    static bool viewDepartmentController(Department& dept, std::string attribute);
};
