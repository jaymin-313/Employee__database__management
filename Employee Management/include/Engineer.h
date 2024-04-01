#ifndef eng_flag
#define eng_flag

#include "Employee.h"
#include "../sqlite/sqlite3.h"
#include "log.h"
#include "Salary.h"
#include "controllers/engineerController.h"

class Engineer : public Employee {
public:
	Engineer() = default;

	Engineer(int emp_id, const std::string& first, const std::string& last, const std::string& date_of_birth,
		const std::string& phone, const std::string& mail, const std::string& addr, const std::string& gen,
		const std::string& date_of_joining, const std::string& work_loc, int mgr_id, int dept_id,
		std::string languages, const std::string& specilize)
		: Employee(emp_id, first, last, date_of_birth, phone, mail, addr, gen, date_of_joining, work_loc, mgr_id, dept_id),
		programming_language(languages), specialization(specilize) {}

	std::string getProgrammingLanguage() const { return programming_language; }
	std::string getSpecialization() const { return specialization; }

	bool setProgrammingLanguage();
	bool setSpecialization();

	bool insertEngineer();
	bool deleteEngineer();
	bool updateEngineer();
	bool viewEngineer();

	void describeEngineer() const;

	void action();

private:

	std::string programming_language {};
	std::string specialization{};
};

#endif