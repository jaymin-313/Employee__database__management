
#include <iostream>
#include "include/database.h"
#include "include/Employee.h"
#include "include/Engineer.h"
#include "include/Manager.h"
#include "include/Salary.h"
#include "include/department.h"

#include "include/menu_controller.h"
int main() {

	if (!Database::getInstance().open("employee.db")) {
		std::cerr << "Error opening database: " << Database::getInstance().getError() << std::endl;
		return 1;
	}

	displayMenu();
	
	Database::getInstance().close();

	return 0;
}
