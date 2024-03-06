
#include "../include/Employee.h"
#include "../include/database.h"
#include "../include/validate.h"

void Employee::setId() {
	std::cout << "ID: ";
	std::cin >> id;
}
void Employee::setFirstname() {
	std::cout << "First Name: ";
	std::cin >> firstname;
}
void Employee::setLastname() {
	std::cout << "Last Name: ";
	std::cin >> lastname;
}
void Employee::setDob() {
	std::cout << "Date of Birth (DD-MM-YYYY): ";
	std::string inputDOB;
	std::cin >> inputDOB;
	if (!validateDateOfBirth(inputDOB)) {
		std::cout << "Invalid Format !!, Enter again :\n";
		Employee::setDob();
	}
	else {
		dob = inputDOB;
	}
}
void Employee::setMobile() {
	std::cout << "Mobile number : ";
	std::string inputMob;
	std::cin >> inputMob;
	if (!validatePhoneNumber(inputMob)) {
		std::cout << "Invalid Format !!, Enter again :\n";
		Employee::setMobile();
	}
	else {
		mobile = inputMob;
	}
}
void Employee::setEmail() {
	std::cout << "Email address : ";
	std::string inputMail;
	std::cin >> inputMail;
	if (!validateEmail(inputMail)) {
		std::cout << "Invalid Format !!, Enter again :\n";
		Employee::setEmail();
	}
	else {
		email = inputMail;
	}
}
void Employee::setAddress() {
	std::cout << "Address: ";
	std::cin.ignore();
	std::getline(std::cin, address);
}
void Employee::setGender() {
	std::cout << "Gender (Male, Female, Other): ";
	std::cin >> gender;
}
void Employee::setDoj() {
	std::cout << "Date of Joining (DD-MM-YYYY): ";
	std::string inputDOJ;
	std::cin >> inputDOJ;
	if (!validateDateOfBirth(inputDOJ)) {
		std::cout << "Invalid Format !!, Enter again :\n";
		Employee::setDoj();
	}
	else {
		doj = inputDOJ;
	}
}
void Employee::setWLocation() {
	std::cout << "Work Location: ";
	std::cin >> w_location;
}
void Employee::setManagerId() {
	std::cout << "Manager ID: ";
	std::cin >> manager_id;
}
void Employee::setDepartmentId() {
	std::cout << "Department ID: ";
	std::cin >> department_id;
}

void Employee::insertEmployee() {

	std::cout << "Enter Employee Details:\n";

	/*setId();
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
		std::to_string(department_id) + ");";*/

	std::string insertQuery = "INSERT INTO Employee (id, firstname, lastname, dob, mobile, email, address, gender, doj, w_location, manager_id, department_id) VALUES"
		"(4, 'Emily', 'Brown', '1987-04-25', '1112223333', 'emily.brown@example.com', '101 Pine St', 'Female', '2016-02-15', 'Office D', 3, 4), "
		"(5, 'David', 'Wilson', '1993-09-30', '9998887777', 'david.wilson@example.com', '202 Maple St', 'Male', '2019-05-10', 'Office E', 4, 5), "
		"(6, 'Sophia', 'Martinez', '1990-06-20', '3334445555', 'sophia.martinez@example.com', '303 Oak St', 'Female', '2014-07-01', 'Office F', 5, 6), "
		"(7, 'James', 'Anderson', '1988-11-15', '7776665555', 'james.anderson@example.com', '404 Cedar St', 'Male', '2015-03-25', 'Office G', 6, 7), "
		"(8, 'Olivia', 'Taylor', '1995-01-05', '5556667777', 'olivia.taylor@example.com', '505 Walnut St', 'Female', '2018-08-10', 'Office H', 7, 8), "
		"(9, 'William', 'Thomas', '1986-07-10', '2223334444', 'william.thomas@example.com', '606 Birch St', 'Male', '2013-09-20', 'Office I', 8, 9), "
		"(10, 'Ava', 'Hernandez', '1991-03-08', '8889990000', 'ava.hernandez@example.com', '707 Pine St', 'Female', '2017-11-05', 'Office J', 9, 10); ";

	if (db_emp.executeQuery(insertQuery))
		std::cout << "Inserted Employee Succesfully ! \n";
	else
		std::cout << db_emp.getError() << "\n";

};
void Employee::deleteEmployee() {

	std::string deleteQuery{};

	int choice;

	std::cout << "Please select a column to delete an employee:\n";
	std::cout << "1. ID\n";
	std::cout << "2. Firstname\n";
	std::cout << "3. Email\n";
	std::cout << "4. Exit\n";

	std::cout << "Enter your choice (1-4): ";


	std::cin >> choice;
	std::cout << "\n";

	switch (choice) {
	case 1:
		setId();
		deleteQuery = "DELETE FROM Employee WHERE id = " + std::to_string(getId());
		break;
	case 2:
		setFirstname();
		deleteQuery = "DELETE FROM Employee WHERE firstname = '" + getFirstname() + "'";
		break;

	case 3:
		setEmail();
		deleteQuery = "DELETE FROM Employee WHERE email = '" + getEmail() + "'";
		break;

	case 4:
		break;
	default:
		std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
		deleteEmployee();
		break;
	}

	if (db_emp.executeQuery(deleteQuery)) {

		int changes = sqlite3_changes(db_emp.db);

		std::cout << changes << " row affected \n\n";
		if (changes != 0) {
			std::cout << "Employee Deleted Succesfully ! \n";
		}

	}
	else
		std::cout << db_emp.getError() << "\n";


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

	if (db_emp.executeQuery(updateQuery)) {

		int changes = sqlite3_changes(db_emp.db);

		std::cout << changes << " row affected \n\n";
		if (changes != 0) {
			std::cout << "Employee Updated Succesfully ! \n";
		}
	}
	else
		std::cout << db_emp.getError() << "\n";

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

	if (!db_emp.executeQueryCallback(selectQuery)) {
		std::cout << db_emp.getError() << std::endl;
	}

};


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
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice (1-5): ";

		std::cin >> choice;
		std::cout << "\n";

		switch (choice) {
		case 1:
			insertEmployee();
			break;
		case 2:
			deleteEmployee();
			break;
		case 3:
			updateEmployee();
			break;
		case 4:
			viewEmployee();
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
