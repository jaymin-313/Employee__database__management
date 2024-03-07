#ifndef dept_flag
#define dept_flag

#include <iostream>
#include <string>
#include "database.h"

class Department {
public:
    Department() = default;

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getManagerId() const { return manager_id; }
    std::string getDescription() const { return description; }

    void setId();
    void setName();
    void setManagerId();
    void setDescription();

    void insertDepartment();
    void deleteDepartment();
    void updateDepartment();
    void viewDepartment();

    void action();

private:

  
    int id{};
    std::string name{};
    int manager_id{};
    std::string description{};
};


#endif