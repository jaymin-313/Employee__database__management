#include "../../include/controllers/engineerController.h"

using logs::Log;

bool EngineerController::insertEngineerController(Engineer& engineer,Salary& salary) {
	
	std::string insertQueryEngineer = "INSERT INTO Engineer (id, programming_language,specialization) VALUES ("
		+ std::to_string(engineer.getId()) + ", '" +
		engineer.getProgrammingLanguage() + "', '" +
		engineer.getSpecialization() + "'" +
		");";


	if (Database::getInstance().executeQuery(insertQueryEngineer) && SalaryController::insertSalaryController(salary)) {
		std::cout << "\033[32mInserted Engineer Succesfully ! \033[0m\n\n";
		Log::getInstance().Info("Engineer Inserted for id : ", engineer.getId());
		return true;
	}
	else {
		std::cout << Database::getInstance().getError() << "\n\n";
		return false;
	}

};

bool EngineerController::deleteEngineerController(Engineer& engineer, std::string attribute) {

	if (!EmployeeController::deleteEmployeeController(engineer, "id")) {
		std::cout << Database::getInstance().getError() << "\n";
		return false;
	}

	int changes = sqlite3_changes(Database::getInstance().db);

	std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
	if (changes != 0) {
		std::cout << "\033[32mEngineer Deleted Successfully ! \033[0m\n\n";
		Log::getInstance().Info("Engineer Deleted for id : ", engineer.getId());
		return true;
	}

	return false;
}

bool EngineerController::updateEngineerController(Engineer& engineer, std::string attribute) {
	
	std::string updateQuery = "UPDATE Engineer SET ";
	if (attribute == "programming_language") {
		updateQuery += " programming_language = '" + engineer.getProgrammingLanguage() + "'";
	}
	else if (attribute == "specialization") {
		updateQuery += " specialization= '" + engineer.getSpecialization() + "'";
	}

	updateQuery += " WHERE id = " + std::to_string(engineer.getId()) + ";";
	if (Database::getInstance().executeQuery(updateQuery)) {

		int changes = sqlite3_changes(Database::getInstance().db);

		std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
		if (changes != 0) {
			std::cout << "\033[32mEngineer Updated Succesfully ! \033[0m\n\n";
			Log::getInstance().Info("Engineer Updated for id : ", engineer.getId());
			return true;
		}

	}
	else {
		std::cout << Database::getInstance().getError() << "\n";
		return false;
	}
}

bool EngineerController::viewEngineerController(std::string selectQuery) {

	if (!Database::getInstance().executeQueryCallback(selectQuery)) {
		std::cout << Database::getInstance().getError() << std::endl;
		return false;
	}
	else {
		Log::getInstance().Info(selectQuery, " : Executed.");
		return true;
	}

}

