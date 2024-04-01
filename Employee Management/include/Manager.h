#ifndef manager_flag
#define manager_flag
#include "Employee.h"
#include "log.h"
#include "validate.h"
#include "Salary.h"
#include "controllers/managerController.h"

class Manager : public Employee {
public:
	Manager() = default;

	Manager(int emp_id, const std::string& first, const std::string& last, const std::string& date_of_birth,
		const std::string& phone, const std::string& mail, const std::string& addr, const std::string& gen,
		const std::string& date_of_joining, const std::string& work_loc, int mgr_id, int dept_id,
		int experience, const std::string& title)
		: Employee(emp_id, first, last, date_of_birth, phone, mail, addr, gen, date_of_joining, work_loc, mgr_id, dept_id),
		management_experience(experience), project_title(title) {}

	int getManagementExperience() const { return management_experience; }
	std::string getProjectTitle() const { return project_title; }

	bool setManagementExperience();
	bool setProjectTitle();

	bool insertManager();
	bool deleteManager();
	bool updateManager();
	bool viewManager();

	void describeManager() const;

	void action();

private:

	int management_experience{};
	std::string project_title{};
};

#endif