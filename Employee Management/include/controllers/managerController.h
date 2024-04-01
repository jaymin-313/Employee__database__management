#pragma once

#include "../Manager.h"
class Manager;

class ManagerController {
public:
    static bool insertManagerController(Manager& manager,Salary& salary);
    static bool deleteManagerController(Manager& manager, std::string attribute);
    static bool updateManagerController(Manager& manager, std::string attribute);
    static bool viewManagerController(std::string selectQuery);
};