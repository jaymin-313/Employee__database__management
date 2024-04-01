#pragma once

#include "../Engineer.h"
class Engineer;

class EngineerController {
public:
    static bool insertEngineerController(Engineer& eng,Salary& salary);
    static bool deleteEngineerController(Engineer& eng, std::string attribute);
    static bool updateEngineerController(Engineer& eng, std::string attribute);
    static bool viewEngineerController(std::string selectQuery);
};