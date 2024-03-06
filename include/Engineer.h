#ifndef eng_flag
#define eng_flag

#include "Employee.h"
class Engineer : public Employee {
public:
	Engineer() = default;
	Engineer(const Database& db) {
		engineer_db = db;
	}
	/*Engineer(int id, const std::string& firstname, const std::string& lastname, const std::string& dob,
		const std::string& mobile, const std::string& email, const std::string& address,
		Gender gender, const std::string& doj, float salary, const std::string& w_location,
		int manager_id, int department_id, const std::string& programming_language,
		const std::string& specialization)
		: Employee(id, firstname, lastname, dob, mobile, email, address, gender, doj,
			w_location, manager_id, department_id),
		programming_language(programming_language), specialization(specialization) {}*/



	std::string getProgrammingLanguage() const { return programming_language; }
	std::string getSpecialization() const { return specialization; }

	void setProgrammingLanguage(const std::string& ProgrammingLanguage) { programming_language = ProgrammingLanguage; }
	void setSpecialization(const std::string& Specialization) { specialization = Specialization; }

	void insertEngineer();
	void deleteEngineer();
	void updateEngineer();
	void viewEngineer();

	void action();

private:

	Database engineer_db;
	std::string programming_language {};
	std::string specialization{};
};

#endif