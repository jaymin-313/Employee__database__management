
#include <iostream>
#include "include/database.h"
#include "include/Employee.h"
#include "include/Engineer.h"
#include "include/Manager.h"
#include "include/Salary.h"
#include "include/department.h"

#include "include/menu_controller.h"
#include "include/log.h"

using logs::Log;
int main() {

	if (!Database::getInstance().open("employee.db")) {
		std::cerr << "Error opening database: " << Database::getInstance().getError() << std::endl;
		return 1;
	}
	else {
		Log::getInstance().Info("Opened Database Succesfully");
	}
	displayMenu();
	
	Database::getInstance().close();

	return 0;
}
