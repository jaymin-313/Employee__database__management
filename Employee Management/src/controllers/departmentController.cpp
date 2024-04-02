#include "../../include/controllers/departmentController.h"

using logs::Log;

bool DepartmentController::insertDepartmentController(Department& dept) {

	std::string managerIdString = (dept.getManagerId() != NULL) ? std::to_string(dept.getManagerId()) : "NULL";

	std::string insertQuery = "INSERT INTO Department (id, name, manager_id, description) VALUES ("
		+ std::to_string(dept.getId()) + ", '" +
		dept.getName() + "', " +
		managerIdString + ", '" +
		dept.getDescription() + "');";

	if (Database::getInstance().executeQuery(insertQuery)) {
		std::cout << "\033[32mInserted Department Successfully! \033[0m\n\n";
		Log::getInstance().Info("Department Inserted for id : ", dept.getId());
		return true;
	}
	else {
		std::cout << Database::getInstance().getError() << "\n";
		return false;
	}
};

bool DepartmentController::deleteDepartmentController(Department& dept, std::string attribute) {
	std::string deleteQuery{};
	if (attribute == "id") {
		deleteQuery = "DELETE FROM Department WHERE id = " + std::to_string(dept.getId());
	}
	else if(attribute == "name"){
		deleteQuery = "DELETE FROM Department WHERE name = '" + dept.getName() + "'";
	}
	else {
		std::cout << "Invalid attribute\n";
		return false;
	}

	if (Database::getInstance().executeQuery(deleteQuery)) {

		int changes = sqlite3_changes(Database::getInstance().db);

		std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
		if (changes != 0) {
			std::cout << "\033[32mDepartment Deleted Succesfully ! \033[0m\n\n";
			Log::getInstance().Info("Department Deleted for id : ", dept.getId());
			
		}
		return true;
	}
	else {
		std::cout << Database::getInstance().getError() << "\n";
		return false;
	}
}

bool DepartmentController::updateDepartmentController(Department& dept, std::string attribute) {
	std::string updateQuery = "UPDATE Department SET ";
	if (attribute == "name") {
		updateQuery += "name = '" + dept.getName() + "'";
	}
	else if (attribute == "manager_id") {
		updateQuery += "manager_id = " + std::to_string(dept.getManagerId());
	}
	else if (attribute == "description") {
		updateQuery += "description = '" + dept.getDescription() + "'";
	}

	updateQuery += " WHERE id = " + std::to_string(dept.getId());

	if (Database::getInstance().executeQuery(updateQuery)) {
		int changes = sqlite3_changes(Database::getInstance().db);
		std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
		if (changes != 0) {
			std::cout << "\033[32mDepartment Updated Successfully ! \033[0m\n\n";
			Log::getInstance().Info("Department Updated for id : ", dept.getId());
		}
		return true;
	}
	else {
		std::cout << Database::getInstance().getError() << "\n";
		return false;
	}
}

bool DepartmentController::viewDepartmentController(Department& dept, std::string attribute) {
	std::string selectQuery{};
	if (attribute == "id") {
		selectQuery = "SELECT department.id,name,description,firstname as manager_name from Department LEFT JOIN Employee where Department.manager_id=Employee.id AND Department.id = " + std::to_string(dept.getId());
	}
	else if (attribute == "name") {
		selectQuery = "SELECT department.id,name,description,firstname as manager_name from Department LEFT JOIN Employee where Department.manager_id=Employee.id AND name = '" + dept.getName() + "'";
	}
	else {
		selectQuery = "SELECT department.id,name,description,firstname as manager_name from Department LEFT JOIN Employee where Department.manager_id=Employee.id;";
	}

	if (!Database::getInstance().executeQueryCallback(selectQuery)) {
		std::cout << Database::getInstance().getError() << "\n";
		return false;
	}
	else {
		Log::getInstance().Info("Department Viewed for " + attribute + " : ", dept.getId());
		return true;
	}
}
