#include "../include/Salary.h"

void Salary::setId() {
	std::cout << "Enter Employee Id: ";
	std::cin >> id;
}
void Salary::setAmount() {
	std::cout << "Enter Amount: ";
	std::cin >> amount;
}
void Salary::setBaseSalary() {
	std::cout << "Enter Base: ";
	std::cin >> base_salary;
}
void Salary::setBonus() {
	std::cout << "Enter Bonus: ";
	std::cin >> bonus;

}

void Salary::insertSalary() {
	std::cout << "Insert Salary Details:\n";
	setId();
	setAmount();
	setBaseSalary();
	setBonus();

	std::string insertQuery = "INSERT INTO Salary (id, amount, base_salary, bonus) VALUES ("
		+ std::to_string(id) + ", '" +
		std::to_string(amount) + "', '" +
		std::to_string(base_salary) + "', '" +
		std::to_string(bonus) + "');";

	if (Database::getInstance().executeQuery(insertQuery))
		std::cout << "Inserted Salary Succesfully ! \n\n";
	else
		std::cout << Database::getInstance().getError() << "\n";

};
void Salary::deleteSalary() {

	setId();
	std::string deleteQuery = "DELETE FROM Salary WHERE id = " + std::to_string(getId());

	if (Database::getInstance().executeQuery(deleteQuery)) {

		int changes = sqlite3_changes(Database::getInstance().db);

		std::cout << changes << " row affected \n\n";
		if (changes != 0) {
			std::cout << "Salary Deleted Succesfully ! \n\n";
		}

	}
	else
		std::cout << Database::getInstance().getError() << "\n";

};
void Salary::updateSalary() {

	std::string updateQuery{};
	int choice;
	std::cout << "Enter Salary id to update: \n";
	std::cin >> id;


	std::cout << "Please select an attribute to update:\n";
	std::cout << "1. Salary Amount\n";
	std::cout << "2. Base Salary\n";
	std::cout << "3. Bonus\n";
	std::cout << "4. Exit\n";
	std::cout << "Enter your choice (1-4): ";

	std::cin >> choice;
	std::cout << "\n";

	switch (choice) {
	case 1:
		setAmount();
		updateQuery = "UPDATE Salary SET amount = '" + std::to_string(getAmount()) + "' WHERE id = " + std::to_string(id);
		break;
	case 2:
		setBaseSalary();
		updateQuery = "UPDATE Salary SET base_salary= '" + std::to_string(getBaseSalary()) + "' WHERE id = " + std::to_string(id);
		break;
	case 3:
		setBonus();
		updateQuery = "UPDATE Salary SET bonus = '" + std::to_string(getBonus()) + "' WHERE id = " + std::to_string(id);
		break;
	case 4:
		break;
	default:
		std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
		updateSalary();
		break;
	}

	if (Database::getInstance().executeQuery(updateQuery)) {

		int changes = sqlite3_changes(Database::getInstance().db);

		std::cout << changes << " row affected \n\n";
		if (changes != 0) {
			std::cout << "Salary Updated Succesfully ! \n\n";
		}

	}
	else
		std::cout << Database::getInstance().getError() << "\n";

};
void Salary::viewSalary() {
	std::string selectQuery{};

	int choice;

	std::cout << "Please select a column to view a Salary:\n";
	std::cout << "1. ALL\n";
	std::cout << "2. Employee Id\n";
	std::cout << "3. Exit\n";

	std::cout << "Enter your choice (1-3): ";


	std::cin >> choice;
	std::cout << "\n";

	switch (choice) {
	case 1:
		selectQuery = "SELECT id,firstname,lastname,email,amount,base_salary,bonus From Employee NATURAL JOIN Salary";
		break;
	case 2:
		setId();
		selectQuery = "SELECT id,firstname,lastname,email,amount,base_salary,bonus From Employee NATURAL JOIN Salary WHERE id = " + std::to_string(getId());
		break;
	case 3:
		break;
	default:
		std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
		viewSalary();
		break;
	}

	if (!Database::getInstance().executeQueryCallback(selectQuery)) {
		std::cout << Database::getInstance().getError() << std::endl;
	}

};


void Salary::action() {
	bool flag = true;

	while (flag) {
		std::cout << "Salary Table\n";
		std::cout << "Please select a value to perform actions:\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Update\n";
		std::cout << "4. View\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice (1-5): ";

		int choice;
		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			insertSalary();
			break;
		case 2:
			deleteSalary();
			break;
		case 3:
			updateSalary();
			break;
		case 4:
			viewSalary();
			break;
		case 5:
			flag = false;
			break;
		default:
			std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
			break;
		}
	}
}