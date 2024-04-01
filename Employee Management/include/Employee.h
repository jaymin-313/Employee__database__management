
#ifndef emp_flag
#define emp_flag

#include <iostream>
#include <string>
#include<vector>
#include "database.h"
#include "attributeHelper.h"
#include "database.h"
#include "validate.h"
#include "log.h"
#include "../include/controllers/employeeController.h"

//#include "validate.h"
//enum class Gender { Male, Female, Other };

class Employee {

public:
    Employee() = default;
    Employee(int emp_id, const std::string& first, const std::string& last, const std::string& date_of_birth,
        const std::string& phone, const std::string& mail, const std::string& addr, const std::string& gen,
        const std::string& date_of_joining, const std::string& work_loc, int mgr_id, int dept_id)
        : id(emp_id), firstname(first), lastname(last), dob(date_of_birth), mobile(phone), email(mail),
        address(addr), gender(gen), doj(date_of_joining), w_location(work_loc), manager_id(mgr_id),
        department_id(dept_id) {}
    
    int getId() const { return id; }
    std::string getFirstname() const { return firstname; }
    std::string getLastname() const { return lastname; }
    std::string getDob() const { return dob; }
    std::string getMobile() const { return mobile; }
    std::string getEmail() const { return email; }
    std::string getAddress() const { return address; }
    std::string getGender() const { return gender; }
    std::string getDoj() const { return doj; }
    std::string getWLocation() const { return w_location; }
    int getManagerId() const { return manager_id; }
    int getDepartmentId() const { return department_id; }

    bool setId();
    bool setFirstname();
    bool setLastname();
    bool setDob();
    bool setMobile();
    bool setEmail();
    bool setAddress();
    bool setGender();
    bool setDoj();
    bool setWLocation();
    bool setManagerId();
    bool setDepartmentId();

    bool insertEmployee();
    bool deleteEmployeeById(int) ;
    bool updateEmployee();
    //void viewEmployee();
    void describeEmployee() const;

    //void action();

private:

    int id{};
    std::string firstname{};
    std::string lastname{};
    std::string dob{};
    std::string mobile{};
    std::string email{};
    std::string address{};
    std::string gender{};
    std::string doj{};
    std::string w_location{};
    int manager_id{};
    int department_id{};
};

#endif