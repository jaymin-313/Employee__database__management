#include "../../include/controllers/employeeController.h"

using logs::Log;

bool EmployeeController::insertEmployeeController(Employee& employee) {
	std::string managerIdString = (employee.getManagerId() != NULL) ? std::to_string(employee.getManagerId()) : "NULL";
	std::string departmentIdString = (employee.getDepartmentId() != NULL) ? std::to_string(employee.getDepartmentId()) : "NULL";

	std::string insertQueryEmployee = "INSERT INTO Employee (id, firstname, lastname, dob, mobile, email, address, gender, doj, w_location, manager_id, department_id) VALUES ("
		+ std::to_string(employee.getId()) + ", '" +
		employee.getFirstname() + "', '" +
		employee.getLastname() + "', '" +
		employee.getDob() + "', '" +
		employee.getMobile() + "', '" +
		employee.getEmail() + "', '" +
		employee.getAddress() + "', '" +
		employee.getGender() + "', '" +
		employee.getDoj() + "', '" +
		employee.getWLocation() + "', " +
		managerIdString + ", " +
		departmentIdString + ");";
	if (Database::getInstance().executeQuery(insertQueryEmployee)) {
		return true;
	}
	else {
		std::cout << Database::getInstance().getError() << "\n\n";
		return false;
	}
};

bool EmployeeController::deleteEmployeeController(Employee& employee, std::string attribute) {

	std::string deleteQuery = "DELETE FROM Employee WHERE id = " + std::to_string(employee.getId());

	if (Database::getInstance().executeQuery(deleteQuery)) {

		int changes = sqlite3_changes(Database::getInstance().db);

		std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
		if (changes != 0) {
			std::cout << "\033[32mEmployee Deleted Succesfully ! \033[0m\n\n";
			Log::getInstance().Info("Employee Deleted for id : ", employee.getId());
			return true;
		}

	}
	else {
		std::string_view errmsg = "FOREIGN KEY constraint failed";
		if (Database::getInstance().getError() == errmsg) {
			std::string err = { "Selected Employee is managing different employees, so you can not directly delete this employee !!! " };
			Database::getInstance().setError(err);
			Log::getInstance().Warn("Selected Employee is managing different employees : can not delete for id : ", employee.getId());
		}
		std::cout << Database::getInstance().getError() << "\n\n";
		return false;
	}
}

bool EmployeeController::updateEmployeeController(Employee& employee, std::string attribute) {

	std::string updateQuery = "UPDATE Employee SET ";
	if (attribute == "firstname") {
		updateQuery += "firstname = '" + employee.getFirstname() + "'";
	}
	else if (attribute == "lastname") {
		updateQuery += "lastname = '" + employee.getLastname() + "'";
	}
	else if (attribute == "dob") {
		updateQuery += "dob = '" + employee.getDob() + "'";
	}
	else if (attribute == "mobile") {
		updateQuery += "mobile = '" + employee.getMobile() + "'";
	}
	else if (attribute == "email") {
		updateQuery += "email = '" + employee.getEmail() + "'";
	}
	else if (attribute == "address") {
		updateQuery += "address = '" + employee.getAddress() + "'";
	}
	else if (attribute == "gender") {
		updateQuery += "gender = '" + employee.getGender() + "'";
	}
	else if (attribute == "doj") {
		updateQuery += "doj = '" + employee.getDoj() + "'";
	}
	else if (attribute == "w_location") {
		updateQuery += "w_location = '" + employee.getWLocation() + "'";
	}
	else if (attribute == "manager_id") {
		updateQuery += "manager_id = " + std::to_string(employee.getManagerId());
	}
	else if (attribute == "department_id") {
		updateQuery += "department_id = " + std::to_string(employee.getDepartmentId());
	}

	updateQuery += " WHERE id = " + std::to_string(employee.getId());

	if (Database::getInstance().executeQuery(updateQuery)) {
		int changes = sqlite3_changes(Database::getInstance().db);
		std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
		if (changes != 0) {
			std::cout << "\033[32mEmployee Updated Successfully ! \033[0m\n\n";
			Log::getInstance().Info("Employee Updated for id : ", employee.getId());
			return true;
		}
	}
	else {
		std::cout << Database::getInstance().getError() << "\n";
	}
	return false;

}

bool EmployeeController::viewEmployeeController(Employee& employee, std::string attribute) {
	std::string selectQuery;

	if (attribute == "ALL") {
		selectQuery = "SELECT * FROM Employee";
	}
	else if (attribute == "ID") {
		employee.setId();
		selectQuery = "SELECT * FROM Employee WHERE id = " + std::to_string(employee.getId());
	}
	else if (attribute == "Firstname") {
		employee.setFirstname();
		selectQuery = "SELECT * FROM Employee WHERE firstname = '" + employee.getFirstname() + "'";
	}
	else if (attribute == "Email") {
		employee.setEmail();
		selectQuery = "SELECT * FROM Employee WHERE email = '" + employee.getEmail() + "'";
	}
	else {
		std::cout << "Invalid attribute\n";
		return false;
	}

	if (!Database::getInstance().executeQueryCallback(selectQuery)) {
		std::cout << Database::getInstance().getError() << std::endl;
		return false;
	}
	else {
		Log::getInstance().Info(selectQuery, " : Executed.");
		return true;
	}
}