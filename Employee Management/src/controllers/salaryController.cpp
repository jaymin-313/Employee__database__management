#include "../../include/controllers/salaryController.h"

using logs::Log;

bool SalaryController::insertSalaryController(Salary& salary) {

	std::string insertQuery = "INSERT INTO Salary (id, base_salary, bonus) VALUES ("
		+ std::to_string(salary.getId()) + ", '" +
		std::to_string(salary.getBaseSalary() ) + "', '" +
		std::to_string(salary.getBonus()) + "');";

	if (Database::getInstance().executeQuery(insertQuery)) {
		return true;
	}
	else {
		std::cout << Database::getInstance().getError() << "\n\n";
		return false;
	}
	
};

bool SalaryController::deleteSalaryController(Salary& salary, std::string attribute) {

	if (attribute == "id") {

		std::string deleteQuery = "DELETE FROM Salary WHERE id = " + std::to_string(salary.getId());

		if (Database::getInstance().executeQuery(deleteQuery)) {

			int changes = sqlite3_changes(Database::getInstance().db);

			std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
			if (changes != 0) {
				std::cout << "\033[32mSalary Deleted Succesfully ! \033[0m\n\n";
				Log::getInstance().Info("Salary Deleted for id : ", salary.getId());
				return true;
			}

		}
		else {
			std::cout << Database::getInstance().getError() << "\n";
		}
	}
	return false;
}

bool SalaryController::updateSalaryController(Salary& salary, std::string attribute) {

	std::string updateQuery = "UPDATE Salary SET ";
	if (attribute == "base_salary") {
		updateQuery += "base_salary = '" + std::to_string(salary.getBaseSalary()) + "'";
	}
	else if (attribute == "bonus") {
		updateQuery += "bonus = '" + std::to_string(salary.getBonus()) + "'";
	}

	updateQuery += " WHERE id = " + std::to_string(salary.getId());

	if (Database::getInstance().executeQuery(updateQuery)) {
		int changes = sqlite3_changes(Database::getInstance().db);
		std::cout << "\033[32m" << changes << " row affected \033[0m\n\n";
		if (changes != 0) {
			std::cout << "\033[32mSalary Updated Successfully ! \033[0m\n\n";
			Log::getInstance().Info("Salary Updated for id : ", salary.getId());
			return true;
		}
	}
	else {
		std::cout << Database::getInstance().getError() << "\n";
	}

	return false;

}

bool SalaryController::viewSalaryController(std::string selectQuery) {
	if (!Database::getInstance().executeQueryCallback(selectQuery)) {
		std::cout << Database::getInstance().getError() << std::endl;
		return false;
	}
	else {
		Log::getInstance().Info(selectQuery, " : Executed.");
		return true;
	}
}

bool SalaryController::incrementSalaryController(Salary& salary)
{

	std::string updateSalary = "UPDATE Salary SET base_salary = base_salary * " + std::to_string(salary.getPercentage()) + " WHERE id = " + std::to_string(salary.getId()) + "; ";

	if (!Database::getInstance().executeQuery(updateSalary)) {
		std::cout << Database::getInstance().getError();
		return false;
	}
	else {
		std::cout << "\033[32mSalary Incremented for id : " << salary.getId() << "\033[0m\n\n";
		Log::getInstance().Info("Salary Incremented for id : ", salary.getId());
		return true;
	}
}
