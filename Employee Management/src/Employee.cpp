
#include "../include/Employee.h"


using logs::Log;

bool Employee::setId() {
	bool result = setAttribute<int>("ID", id, validateNumeric);
    return result;
}

bool Employee::setFirstname() {
	bool result = setAttribute<std::string>("First Name", firstname, validateAlphabetic);
    return result;
}

bool Employee::setLastname() {
	bool result = setAttribute<std::string>("Last Name", lastname, validateAlphabetic);
    return result;
}

bool Employee::setDob() {
	bool result = setAttribute<std::string>("Date of Birth (DD-MM-YYYY)", dob, validateDateOfBirth);
    return result;
}

bool Employee::setMobile() {
	bool result = setAttribute<std::string>("Mobile number", mobile, validatePhoneNumber);
    return result;
}

bool Employee::setEmail() {
	bool result=setAttribute<std::string>("Email address", email, validateEmail);
    return result;
}

bool Employee::setAddress() {
	std::cout << "Address: ";
	std::cin.ignore();
	std::getline(std::cin, address);
    return true;
    /*bool result = setAttribute("Address", address, validateAlphabetic);
    return result;*/
}

bool Employee::setGender() {
    bool result = setAttribute<std::string>("Gender (Male, Female, Other)", gender, [](const std::string& input) {
		return input == "Male" || input == "Female" || input == "Other";
		});
    return result;
}

bool Employee::setDoj() {
	bool result = setAttribute<std::string>("Date of Joining (DD-MM-YYYY)", doj, validateDateOfBirth);
    return result;
}

bool Employee::setWLocation() {
	bool result = setAttribute<std::string>("Work Location", w_location, validateAlphabetic);
    return result;
}

bool Employee::setManagerId() {
	bool result = setAttribute<int>("Manager ID (-1 for null)", manager_id, validateNumeric);
	if (manager_id == -1) {
		manager_id = NULL;
	}
    return result;
}
 
bool Employee::setDepartmentId() {
	bool result = setAttribute<int>("Department ID (-1 for null)", department_id, validateNumeric);
	if (department_id == -1) {
		department_id = NULL;
	}
    return result;
}

bool Employee::insertEmployee() {
	system("cls");
	std::cout << "Enter Employee Details:\n";

    if (!setId()) {
        return false;
    };
	if (Database::getInstance().checkExist("Employee", id)) {
		std::cout << "\033[33mEmployee already exist for id: " << id << "\033[0m\n\n";
		return false;
	}
    if (setFirstname() && setLastname() && setDob() && setMobile() && setEmail() && setAddress()
        && setGender() && setDoj() && setWLocation() && setManagerId() && setDepartmentId()) {
        return EmployeeController::insertEmployeeController(*this); 
    }
    return false;
}

bool Employee::deleteEmployeeById(int eid) {

	id = eid;

	std::string deleteQuery{};

	std::string viewEmployee = "SELECT id,firstname,lastname,email FROM Employee WHERE id = " + std::to_string(id);

	if (!Database::getInstance().executeQueryCallback(viewEmployee,false)) {
		std::cout << Database::getInstance().getError() << std::endl;
		return false;
	}

	std::cout << "\033[36mEnter Y: to delete this Employee\nEnter N: to exit\033[0m\n";
	char confirm;
	std::cin >> confirm;

	if (confirm == 'Y' || confirm == 'y') {
        return EmployeeController::deleteEmployeeController(*this, "id");
	}
    return false;
};

bool Employee::updateEmployee() {

    int choice;
    bool controllerResult;

    system("cls");

    if (!setId()) {
        return false;
    };

    if (!Database::getInstance().checkExist("Employee", id)) {
        std::cout << "\033[33mEmployee Not exist for id: " << id << "\033[0m\n\n";
        return false;
    }

    bool flag = true;
    while (flag) {
        flag = false;
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
        std::cout << "12. Go Back\n";
        std::cout << "Enter your choice (1-12): ";

        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
        case 1:
            if (!setFirstname()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "firstname");
            break;
        case 2:
            if (!setLastname()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "lastname");
            break;
        case 3:
            if (!setDob()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "dob");
            break;
        case 4:
            if (!setMobile()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "mobile");
            break;
        case 5:
            if (!setEmail()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "email");
            break;
        case 6:
            if (!setAddress()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "address");
            break;
        case 7:
            if (!setGender()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "gender");
            break;
        case 8:
            if (!setDoj()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "doj");
            break;
        case 9:
            if (!setWLocation()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "w_location");
            break;
        case 10:
            if (!setManagerId()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "manager_id");
            break;
        case 11:
            if (!setDepartmentId()) {
                return false;
            };
            controllerResult = EmployeeController::updateEmployeeController(*this, "department_id");
            break;
        case 12:
            return true;

        default:
            system("cls");
            std::cout << "Invalid choice. Please enter a number between 1 and 12.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            flag = true;
            break;
        }
    }
    return controllerResult;
}

void Employee::describeEmployee() const
{

	if (!Database::getInstance().executeQueryCallback("pragma table_info('Employee');")) {
		std::cout << Database::getInstance().getError();
	}
	else {
		Log::getInstance().Info("Employee Described.");
	}

}

