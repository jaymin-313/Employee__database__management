
#ifndef emp_flag
#define emp_flag

#include <iostream>
#include <string>
#include<vector>
#include "database.h"


//#include "validate.h"
//enum class Gender { Male, Female, Other };

class Employee {

public:
    Employee() = default;

    
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

    void setId();
    void setFirstname();
    void setLastname();
    void setDob();
    void setMobile();
    void setEmail();
    void setAddress();
    void setGender();
    void setDoj();
    void setWLocation();
    void setManagerId();
    void setDepartmentId();

    bool insertEmployee();
    void deleteEmployeeById(int id);
    void updateEmployee();
    void viewEmployee();

    void describeEmployee();

    void action();

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