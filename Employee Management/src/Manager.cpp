#include "../include/Manager.h"

using logs::Log;

bool Manager::setManagementExperience() {
	bool result = setAttribute("Enter Manager Experience in years", management_experience, validateNumeric);
	return result;
}

bool Manager::setProjectTitle() {
	std::cout << "Enter Manager's Project Title: ";
	std::cin.ignore();
	std::getline(std::cin, project_title);
	return true;
	/*bool result = setAttribute("Project Title", project_title, validateAlphabetic);
	return result;*/

}

bool Manager::insertManager() {
	if (!insertEmployee()) {
		return false;
	}
	if (setManagementExperience() && setProjectTitle()) {
		Salary s1;
		auto s2 = s1.insertSalaryById(getId());

		return ManagerController::insertManagerController(*this,s2);
	}
	EmployeeController::deleteEmployeeController(*this, "id");
	return false;
}

bool Manager::deleteManager() {
	if (!setId()) {
		return false;
	};
	if (!Database::getInstance().checkExist("Manager", getId())) { 
		std::cout << "\033[33mManager Not exist" << "\033[0m\n\n";
		Log::getInstance().Warn("Manager Not exist for id : ", getId());
		return false;
	}
	std::string viewEmployee = "SELECT id,firstname,lastname,email FROM Employee WHERE id = " + std::to_string(getId());

	if (!Database::getInstance().executeQueryCallback(viewEmployee, false)) {
		std::cout << Database::getInstance().getError() << std::endl;
		return false;
	}

	std::cout << "\033[36mEnter Y: to delete this Employee\nEnter N: to exit\033[0m\n";
	char confirm;
	std::cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {
		return ManagerController::deleteManagerController(*this, "id");
	}

	return false;
	
}

bool Manager::updateManager() {
	int choice;
	bool controllerResult{};
	std::string updateQuery = "UPDATE Manager SET ";
	int eid{};

	bool flag = true;
	std::cout << "1. To update Employee Table related details\n";
	std::cout << "2. To update Manager Table related details\n";

	std::cout << "Select from above given choices:";
	std::cin >> choice;
	switch (choice) {
	case 1:
		system("cls");
		if (updateEmployee()) {
			return true;
		}
		else {
			return false;
		}
		break;
	case 2:
		system("cls");

		while (flag) {
			flag = false;
			std::cout << "Enter Employee id to update: \n";
			std::cin >> eid;

			if (!Database::getInstance().checkExist("Manager", eid)) {
				std::cout << "\033[33mManager Not exist for id: " << eid << "\033[0m\n\n";
				return false;
			}

			std::cout << "Please select an attribute to update:\n";
			std::cout << "1. Manager's Experience\n";
			std::cout << "2. Project Title\n";
			std::cout << "3. Go Back\n";
			std::cout << "Enter your choice (1-3): ";
			std::cin >> choice;
			std::cout << "\n";

			switch (choice) {
			case 1:
				if (!setManagementExperience()) {
					return false;
				};
				controllerResult = ManagerController::updateManagerController(*this, "management_experience");
				break;
			case 2:
				if (!setProjectTitle()) {
					return false;
				};
				controllerResult = ManagerController::updateManagerController(*this, "project_title");
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
		break;
	default:
		system("cls");
		std::cout << "Invalid choice. Please enter a number 1 or 2 only\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
	return controllerResult;
}

bool Manager::viewManager() {
	std::string selectQuery{};
	bool flag = true;
	int choice;
	while (flag) {
		std::cout << "Please select a column to view a Manager:\n";
		std::cout << "1. ALL\n";
		std::cout << "2. Employee Id\n";
		std::cout << "3. Employees under Manager\n";
		std::cout << "4. Order by column\n";
		std::cout << "5. Go Back\n";

		std::cout << "Enter your choice (1-5): ";

		flag = false;
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			system("cls");
			selectQuery = "SELECT * FROM Employee NATURAL JOIN Manager WHERE Employee.id==Manager.id ";
			break;
		case 2:
			system("cls");
			if (!setId()) {
				return false;
			};
			selectQuery = "SELECT * FROM Employee NATURAL JOIN Manager WHERE Employee.id==Manager.id AND Employee.id =" + std::to_string(getId());
			break;
		case 3:
			system("cls");
			if (!setId()) {
				return false;
			};
			selectQuery = "SELECT * FROM Employee NATURAL JOIN Engineer WHERE Employee.id = Engineer.id AND manager_id =" + std::to_string(getId());
			break;
		case 4:
		{
			selectQuery = "SELECT * FROM Employee NATURAL JOIN Manager WHERE Employee.id==Manager.id";
			system("cls");
			int choice2;
			std::cout << "Select column to order by:\n";
			std::cout << "1. Firstname\n";
			std::cout << "2. Lastname\n";
			std::cout << "3. Date of Joining\n";
			std::cout << "4. Experience\n";

			std::cin >> choice2;

			std::string orderByColumnName;
			switch (choice2) {
			case 1:
				orderByColumnName = "firstname";
				break;
			case 2:
				orderByColumnName = "lastname";
				break;
			case 3:
				orderByColumnName = "doj";
				break;
			case 4:
				orderByColumnName = "management_experience";
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
		case 5:
			system("cls");
			return true;
		default:
			system("cls");
			std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			flag = true;
			break;
		}
	}
	return ManagerController::viewManagerController(selectQuery);
}

void Manager::describeManager() const
{

	if (!Database::getInstance().executeQueryCallback("pragma table_info('Manager');")) {
		std::cout << Database::getInstance().getError();
	}
	else {
		Log::getInstance().Info("Manager Described.");
	}

}

void Manager::action() {
	bool flag = true;

	while (flag) {
		std::cout << "Manager Table\n";
		std::cout << "Please select a value to perform actions:\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Update\n";
		std::cout << "4. View\n";
		std::cout << "5. Describe\n";
		std::cout << "6. Go Back\n";
		std::cout << "Enter your choice (1-6): ";

		int choice;
		std::cin >> choice;


		switch (choice) {
		case 1:
			system("cls");
			insertManager();
			break;
		case 2:
			system("cls");
			deleteManager();
			break;
		case 3:
			system("cls");
			updateManager();
			break;
		case 4:
			system("cls");
			viewManager();
			break;
		case 5:
			system("cls");
			describeManager();
			break;
		case 6:
			system("cls");
			flag = false;
			break;
		default:
			system("cls");
			std::cerr << "Invalid choice. Please enter a number between 1 and 6.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}
