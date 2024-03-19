
#include "../include/Employee.h"
#include "../include/database.h"
#include "../include/validate.h"
#include "../include/log.h"
using logs::Log;
void Employee::setId() {
	std::cout << "Enter Employee Id: ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateNumeric(inputValidate)) {
		id = std::stoi(inputValidate);
	}
	else {
		std::cout << "Wrong Input!\n";
		setId();
	}
}
void Employee::setFirstname() {
	std::cout << "Enter Employee First Name: ";

	std::string inputValidate;
	std::cin.ignore();
	std::getline(std::cin, inputValidate);
	if (validateAlphabetic(inputValidate)) {
		firstname = inputValidate;
	}
	else {
		std::cout << "Wrong Input!\n";
		setFirstname();
	}
}
void Employee::setLastname() {
	std::cout << "Enter Employee Last Name: ";

	std::string inputValidate;
	std::cin.ignore();
	std::getline(std::cin, inputValidate);
	if (validateAlphabetic(inputValidate)) {
		lastname = inputValidate;
	}
	else {
		std::cout << "Wrong Input!\n";
		setLastname();
	}
}
void Employee::setDob() {
	std::cout << " Enter Date of Birth (DD-MM-YYYY): ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateDateOfBirth(inputValidate)) {
		dob = inputValidate;
	}
	else {
		std::cout << "Invalid Format !!, Enter again :\n";
		setDob();
	}
}
void Employee::setMobile() {
	std::cout << " Enter Mobile number : ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validatePhoneNumber(inputValidate)) {
		mobile = inputValidate;
		
	}
	else {
		std::cout << "Invalid Format !!, Enter again :\n";
		setMobile();
	}
}
void Employee::setEmail() {
	std::cout << "Enter Email address : ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateEmail(inputValidate)) {
		email = inputValidate;
	}
	else {
		std::cout << "Invalid Format !!, Enter again :\n";
		setEmail();
	}
}
void Employee::setAddress() {
	std::cout << "Enter Address: ";
	std::string inputValidate;

	std::cin.ignore();
	std::getline(std::cin, inputValidate);
	if (validateAlphaNumeric(inputValidate)) {
		address = inputValidate;
	}
	else {
		std::cout << "Wrong Input!\n";
		setAddress();
	}
}
void Employee::setGender() {
	std::cout << "Gender (Male, Female, Other): ";
	std::cin >> gender;
}
void Employee::setDoj() {
	std::cout << "Enter Date of Joining (DD-MM-YYYY): ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateDateOfBirth(inputValidate)) {
		doj = inputValidate;
	}
	else {
		std::cout << "Invalid Format !!, Enter again :\n";
		setDoj();
	}
}
void Employee::setWLocation() {
	std::cout << "Enter Work Location: ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateAlphabetic(inputValidate)) {
		w_location = inputValidate;
	}
	else {
		std::cout << "Wrong Input!\n";
		setWLocation();
	}
}
void Employee::setManagerId() {
	std::cout << "Enter Manager ID: ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateNumeric(inputValidate)) {
		manager_id = std::stoi(inputValidate);
	}
	else {
		std::cout << "Wrong Input!\n";
		setManagerId();
	}
}
void Employee::setDepartmentId() {
	std::cout << "Enter Department ID: ";
	std::string inputValidate;
	std::cin >> inputValidate;
	if (validateNumeric(inputValidate)) {
		department_id= std::stoi(inputValidate);
	}
	else {
		std::cout << "Wrong Input!\n";
		setDepartmentId();
	}
}

bool Employee::insertEmployee() {

	system("cls");

	std::cout << "Enter Employee Details:\n";

	setId();
	setFirstname();
	setLastname();
	setDob();
	setMobile();
	setEmail();
	setAddress();
	setGender();
	setDoj();
	setWLocation();
	setManagerId();
	setDepartmentId();

	std::string insertQuery = "INSERT INTO Employee (id, firstname, lastname, dob, mobile, email, address, gender, doj, w_location, manager_id, department_id) VALUES ("
		+ std::to_string(id) + ", '" +
		firstname + "', '" +
		lastname + "', '" +
		dob + "', '" +
		mobile + "', '" +
		email + "', '" +
		address + "', '" +
		gender + "', '" +
		doj + "', '" +
		w_location + "', " +
		std::to_string(manager_id) + ", " +
		std::to_string(department_id) + ");";


	if (!Database::getInstance().executeQuery(insertQuery)) {
		std::cout << Database::getInstance().getError() << "\n\n";
		return false;
	}
	else {
		Log::getInstance().Info("Employee Inserted for id : ", getId());
	}
	return true;

};
void Employee::deleteEmployeeById(int id) {

	std::string deleteQuery{};


	std::string viewEmployee = "SELECT id,firstname,lastname,email FROM Employee WHERE id = " + std::to_string(id);

	if (!Database::getInstance().executeQueryCallback(viewEmployee)) {
		std::cout << Database::getInstance().getError() << std::endl;
	}

	std::cout << "Enter Y: to delete this Employee\nEnter N: to exit\n\n";
	char confirm;
	std::cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {

		deleteQuery = "DELETE FROM Employee WHERE id = " + std::to_string(id);

		if (Database::getInstance().executeQuery(deleteQuery)) {

			int changes = sqlite3_changes(Database::getInstance().db);

			std::cout << changes << " row affected \n\n";
			if (changes != 0) {
				std::cout << "Employee Deleted Succesfully ! \n\n";
			}

		}
		else {
			std::string errmsg = "FOREIGN KEY constraint failed";
			if (Database::getInstance().getError() == errmsg) {
				Database::getInstance().setError("Selected Employee is managing different employees, so you can not directly delete this employee !!! ");
			}
			std::cout << Database::getInstance().getError() << "\n\n";
		}
	}

};

void Employee::updateEmployee() {
	std::string updateQuery{};
	int choice;
	setId();


	std::cout << "Please select an attribute to update:\n";
	std::cout << "1. Firstname\n";
	std::cout << "2. Lastname\n";
	std::cout << "3. Date of Birth\n";
	std::cout << "4. Mobile number\n";
	std::cout << "5. Email address\n";
	std::cout << "6. Address\n";
	std::cout << "7. Gender\n";
	std::cout << "8. Date of Joining\n";
	std::cout << "9. Work Location\n";
	std::cout << "10. Manager ID\n";
	std::cout << "11. Department ID\n";
	std::cout << "12. Exit\n";
	std::cout << "Enter your choice (1-12): ";

	std::cin >> choice;
	std::cout << "\n";

	switch (choice) {
	case 1:
		setFirstname();
		updateQuery = "UPDATE Employee SET firstname = '" + getFirstname() + "' WHERE id = " + std::to_string(id);
		break;
	case 2:
		setLastname();
		updateQuery = "UPDATE Employee SET lastname = '" + getLastname() + "' WHERE id = " + std::to_string(id);
		break;
	case 3:
		setDob();
		updateQuery = "UPDATE Employee SET dob = '" + getDob() + "' WHERE id = " + std::to_string(id);
		break;
	case 4:
		setMobile();
		updateQuery = "UPDATE Employee SET mobile = '" + getMobile() + "' WHERE id = " + std::to_string(id);
		break;
	case 5:
		setEmail();
		updateQuery = "UPDATE Employee SET email = '" + getEmail() + "' WHERE id = " + std::to_string(id);
		break;
	case 6:
		setAddress();
		updateQuery = "UPDATE Employee SET address = '" + getAddress() + "' WHERE id = " + std::to_string(id);
		break;
	case 7:
		setGender();
		updateQuery = "UPDATE Employee SET gender = '" + getGender() + "' WHERE id = " + std::to_string(id);
		break;
	case 8:
		setDoj();
		updateQuery = "UPDATE Employee SET doj = '" + getDoj() + "' WHERE id = " + std::to_string(id);
		break;
	case 9:
		setWLocation();
		updateQuery = "UPDATE Employee SET w_location = '" + getWLocation() + "' WHERE id = " + std::to_string(id);
		break;
	case 10:
		setManagerId();
		updateQuery = "UPDATE Employee SET manager_id = " + std::to_string(manager_id) + " WHERE id = " + std::to_string(id);
		break;
	case 11:
		setDepartmentId();
		updateQuery = "UPDATE Employee SET department_id = " + std::to_string
		(department_id) +" WHERE id = " + std::to_string(id);
		break;
	case 12:
		break;
	default:
		std::cout << "Invalid choice. Please enter a number between 1 and 12.\n";
		updateEmployee();
		break;
	}

	if (Database::getInstance().executeQuery(updateQuery)) {

		int changes = sqlite3_changes(Database::getInstance().db);

		std::cout << changes << " row affected \n\n";
		if (changes != 0) {
			std::cout << "Employee Updated Succesfully ! \n";
		}
	}
	else
		std::cout << Database::getInstance().getError() << "\n";

}


void Employee::viewEmployee() {


	std::string selectQuery{};
	int choice;

	std::cout << "Please select a column to view an employee:\n";
	std::cout << "1. ALL\n";
	std::cout << "2. ID\n";
	std::cout << "3. Firstname\n";
	std::cout << "4. Gmail\n";
	std::cout << "5. Exit\n";

	std::cout << "Enter your choice (1-5): ";


	std::cin >> choice;
	std::cout << "\n";

	switch (choice) {
	case 1:
		selectQuery = "SELECT * FROM Employee";
		break;
	case 2:
		setId();
		selectQuery = "SELECT * FROM Employee WHERE id = " + std::to_string(getId());
		break;
	case 3:
		setFirstname();
		selectQuery = "SELECT * FROM Employee WHERE firstname = '" + getFirstname() + "'";
		break;

	case 4:
		setEmail();
		selectQuery = "SELECT * FROM Employee WHERE email = '" + getEmail() + "'";
		break;

	case 5:
		break;

	default:
		std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
		viewEmployee();
		break;
	}

	if (!Database::getInstance().executeQueryCallback(selectQuery)) {
		std::cout << Database::getInstance().getError() << std::endl;
	}
	else {
		Log::getInstance().Info(selectQuery, " : Executed.");
	}
};

void Employee::describeEmployee()
{

	if (!Database::getInstance().executeQueryCallback("pragma table_info('Employee');")) {
		std::cout << Database::getInstance().getError();
	}
	else {
		Log::getInstance().Info("Employee Described.");
	}

}

void Employee::action() {
	bool flag = true;

	int choice;


	while (flag) {
		std::cout << "Employee Table\n";
		std::cout << "Please select a value to perform actions:\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Update\n";
		std::cout << "4. View\n";
		std::cout << "5. Describe\n";
		std::cout << "6. Restore old data\n";
		std::cout << "7. Exit\n";
		std::cout << "Enter your choice (1-7): ";

		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			insertEmployee();
			break;
		case 2:
			deleteEmployeeById(id);
			break;
		case 3:
			updateEmployee();
			break;
		case 4:
			viewEmployee();
			break;
		case 5:
			describeEmployee();
			break;
		case 6:
			Database::getInstance().import_from_csv("Employee", "Employee.csv");
			std::cout << "Employee data restored from file\n";
			break;
		case 7:
			flag = false;
			break;
		default:
			std::cout << "Invalid choice. Please enter a number between 1 and 7.\n";
			break;
		}
	}
}
