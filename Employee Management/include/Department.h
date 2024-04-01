#ifndef dept_flag
#define dept_flag

#include <iostream>
#include <string>
#include "database.h"
#include "log.h"
#include "validate.h"
#include "attributeHelper.h"
#include "controllers/departmentController.h"

class Department {
public:
    Department() = default;
    Department(int dept_id, const std::string& dept_name, int mgr_id, const std::string& dept_description)
        : id(dept_id), name(dept_name), manager_id(mgr_id), description(dept_description) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getManagerId() const { return manager_id; }
    std::string getDescription() const { return description; }

    bool setId();
    bool setName();
    bool setManagerId();
    bool setDescription();

    bool insertDepartment();
    bool deleteDepartment();
    bool updateDepartment();               
    bool viewDepartment();

    void describeDepartment() const;

    void action();

private:

    int id{};
    std::string name{};
    int manager_id{};
    std::string description{};
};


#endif