#include "../include/Salary.h"


using logs::Log;

bool Salary::setId() {
	bool result = setAttribute("Enter Employee Id", id, validateNumeric);
	return result;
}

bool Salary::setBaseSalary() {
	bool result = setAttribute("Enter Base", base_salary, validateFloatNumeric);
	return result;
}

bool Salary::setBonus() {
	bool result = setAttribute("Enter Bonus", bonus, validateFloatNumeric);
	return result;
}

bool Salary::setPercentage() {
	bool result = setAttribute("Enter Increment Percentage", percentage, validateNumeric);
	percentage = (percentage / 100) + 1;
	return result;
}

Salary Salary::insertSalaryById(int eid) {
	id = eid;
	if (setBaseSalary() && setBonus()) {
		return *this;
	}
	return *this;
};

bool Salary::deleteSalary() {

	system("cls");
	if (!setId()) {
		return false;
	};
	
	return SalaryController::deleteSalaryController(*this, "id");

};

bool Salary::updateSalary() {
	int choice;
	bool controllerResult;
	system("cls");
	std::string updateQuery = "UPDATE Salary SET ";

	std::cout << "Enter Salary id to update: \n";
	std::cin >> id;

	if (!Database::getInstance().checkExist("Salary", id)) {
		std::cout << "\033[33mSalary Not exist for id: " << id << "\033[0m\n\n";
		return false;
	}

	bool flag = true;
	while (flag) {
		flag = false;
		std::cout << "Please select an attribute to update:\n";
		std::cout << "1. Base Salary\n";
		std::cout << "2. Bonus\n";
		std::cout << "3. Go Back\n";
		std::cout << "Enter your choice (1-3): ";

		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			if (!setBaseSalary()) {
				return false;
			};
			controllerResult = SalaryController::updateSalaryController(*this, "base_salary");
			break;
		case 2:
			if (!setBonus()) {
				return false;
			};
			controllerResult = SalaryController::updateSalaryController(*this, "bonus");
			break;
		case 3:
			return true;
		default:
			system("cls");
			std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			flag = true;
			break;
		}
	}
	return controllerResult;
}

bool Salary::incrementSalary() {

	bool set = setId();
	if (!set)
		return false;
	std::string checkExistance = "SELECT id FROM Employee WHERE id = " + std::to_string(id);

	if (!Database::getInstance().checkExist("Employee", id)) {
		std::cout << "\033[33mEmployee Not exist for id: " << id << "\033[0m\n\n";
		return false;
	}
	if (!setPercentage()) {
		return false;
	};

	return SalaryController::incrementSalaryController(*this);
}

bool Salary::viewSalary() {
	std::string selectQuery = "SELECT id,firstname,lastname,email,amount,base_salary,bonus FROM Employee NATURAL JOIN Salary";

	int choice;
	bool flag = true;
	while (flag) {
		system("cls");
		flag = false;
		std::cout << "Please select a column to view a Salary:\n";
		std::cout << "1. ALL\n";
		std::cout << "2. Employee Id\n";
		std::cout << "3. Order By column name\n";
		std::cout << "4. Go Back\n";

		std::cout << "Enter your choice (1-4): ";

		std::cin >> choice;
		std::cout << "\n";
		switch (choice) {
		case 1:
			system("cls");
			break;
		case 2:
			system("cls");
			if (!setId()) {
				return false;
			};
			selectQuery += " WHERE id = " + std::to_string(getId());
			break;
		case 3:
		{
			system("cls");
			int choice2;
			std::cout << "Select column to order by:\n";
			std::cout << "1. Base Salary\n";
			std::cout << "2. Amount\n";
			std::cin >> choice2;

			std::string orderByColumnName;
			switch (choice2) {
			case 1:
				orderByColumnName = "base_salary";
				break;
			case 2:
				orderByColumnName = "amount";
				break;
			default:
				std::cout << "Invalid input!\n";
				break;
			}

			if (!orderByColumnName.empty()) {
				int orderDirection;
				std::cout << "Select order direction:\n";
				std::cout << "1. Ascending\n";
				std::cout << "2. Descending\n";
				std::cin >> orderDirection;

				std::string orderDirectionStr = (orderDirection == 1) ? "ASC" : "DESC";
				selectQuery += " ORDER BY " + orderByColumnName + " " + orderDirectionStr;
			}
			break;
		}
		case 4:
			system("cls");
			return true;
		default:
			system("cls");
			std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			flag = true;
			break;
		}
	}
	return SalaryController::viewSalaryController(selectQuery);
}

void Salary::describeSalary() const
{

	if (!Database::getInstance().executeQueryCallback("pragma table_info('Salary');")) {
		std::cout << Database::getInstance().getError();
	}
	else {
		Log::getInstance().Info("Salary Described.");
	}
}

void Salary::action() {
	bool flag = true;

	while (flag) {
		std::cout << "Salary Table\n";
		std::cout << "Please select a value to perform actions:\n";
		std::cout << "1. Update\n";
		std::cout << "2. View\n";
		std::cout << "3. Describe\n";
		std::cout << "4. Increment Salary\n";
		std::cout << "5. Go Back\n";
		std::cout << "Enter your choice (1-5): ";

		int choice;

		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			system("cls");
			updateSalary();
			break;
		case 2:
			system("cls");
			viewSalary();
			break;
		case 3:
			system("cls");
			describeSalary();
			break;
		case 4:
			system("cls");
			incrementSalary();
			break;
		case 5:
			system("cls");
			flag = false;
			break;
		default:
			system("cls");
			std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

