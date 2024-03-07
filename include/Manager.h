#ifndef manager_flag
#define manager_flag
#include "Employee.h"

class Manager : public Employee {
public:
    Manager() = default;
 
   /* Manager(int id, const std::string& firstname, const std::string& lastname, const std::string& dob,
        const std::string& mobile, const std::string& email, const std::string& address,
        Gender gender, const std::string& doj, float salary, const std::string& w_location,
        int manager_id, int department_id, int management_experience,
        const std::string& project_title)
        : Employee(id, firstname, lastname, dob, mobile, email, address, gender, doj,
            w_location, manager_id, department_id),
        management_experience(management_experience), project_title(project_title) {}*/

    int getManagementExperience() const { return management_experience; }
    std::string getProjectTitle() const { return project_title; }

    void setManagementExperience();
    void setProjectTitle();

    void insertManager();
    void deleteManager();
    void updateManager();
    void viewManager();

    void action();

private:

    int management_experience{};
    std::string project_title{};
};

#endif