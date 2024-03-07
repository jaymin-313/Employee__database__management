#ifndef eng_flag
#define eng_flag

#include "Employee.h"
class Engineer : public Employee {
public:
	Engineer() = default;

	std::string getProgrammingLanguage() const { return programming_language; }
	std::string getSpecialization() const { return specialization; }

	void setProgrammingLanguage();
	void setSpecialization();

	void insertEngineer();
	void deleteEngineer();
	void updateEngineer();
	void viewEngineer();

	void action();


private:

	std::string programming_language{};
	std::string specialization{};
};

#endif