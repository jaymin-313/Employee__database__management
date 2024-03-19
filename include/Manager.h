#ifndef manager_flag
#define manager_flag
#include "Employee.h"

class Manager : public Employee {
public:
    Manager() = default;

    int getManagementExperience() const { return management_experience; }
    std::string getProjectTitle() const { return project_title; }

    void setManagementExperience();
    void setProjectTitle();

    void insertManager();
    void deleteManager();
    void updateManager();
    void viewManager();

    void describeManager();

    void action();

private:

    int management_experience{};
    std::string project_title{};
};

#endif