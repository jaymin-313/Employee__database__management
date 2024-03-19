#pragma once
#include <iostream>
#include "database.h"
#include "Employee.h"
#include "Engineer.h"
#include "Manager.h"
#include "Salary.h"
#include "department.h"
#include<limits>
void createTable() {
	std::string createTableQuery = Database::getInstance().generateCreateTableQuery();
	std::cout << createTableQuery << std::endl;
	/*if (Database::getInstance().executeQuery(createTableQuery))
			std::cout << "Table Created Succesfully ! \n\n";
		else
			std::cout << Database::getInstance().getError() << "\n";*/
		
}

void showTable() {
	std::string showQuery = " SELECT name FROM sqlite_schema ;";
	if (Database::getInstance().executeQueryCallback(showQuery))
		std::cout << "Tables Details Fetched Succesfully ! \n\n";
	else
		std::cout << Database::getInstance().getError() << "\n";
}

void manipulateDB() {
	bool tableFlag = true;
	int tableChoice;
	while (tableFlag) {
		std::cout << "Please select a table to perform an action:\n";
		std::cout << "1. Employee\n";
		std::cout << "2. Department\n";
		std::cout << "3. Salary\n";
		std::cout << "4. Engineer\n";
		std::cout << "5. Manager\n";
		std::cout << "6. Exit\n";
		std::cout << "Enter your choice (1-6): ";


		std::cin >> tableChoice;
		std::cout << "\n";

		switch (tableChoice) {
		case 1:
		{
			Employee e1;
			e1.action();
		}
		break;
		case 2:
		{
			Department d1;
			d1.action();
		}
		break;
		case 3:
		{
			Salary s1;
			s1.action();
		}
		break;
		case 4:
		{
			Engineer en1;
			en1.action();
		}
		break;
		case 5:
		{
			Manager m1;
			m1.action();
		}
		break;
		case 6:
			tableFlag = false;
			break;
		default:
			std::cerr << "Invalid choice. Please enter a number between 1 and 6.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

void deleteTable() {
	int input;
	std::cout << "Enter 1 to Delete table or Enter 2 to truncate table:";
	std::cin >> input;
	std::cout << std::endl;
	std::string deleteQuery;
	std::string tableName;
	switch (input) {
	case 1:
		std::cout << "Enter Table Name to Delete: ";
		std::cin >> tableName;
		deleteQuery = "DROP TABLE " + tableName + ";";
		std::cout << deleteQuery << '\n';
		/*if (Database::getInstance().executeQuery(deleteQuery))
			std::cout << "Table Deleted Succesfully ! \n\n";
		else
			std::cout << Database::getInstance().getError() << "\n";*/
		break;
	case 2:
		std::cout << "Enter Table Name to Truncate: ";
		std::cin >> tableName;
		deleteQuery = "TRUNCATE TABLE " + tableName + ";";
		std::cout << deleteQuery << '\n';
		/*if (Database::getInstance().executeQuery(deleteQuery))
			std::cout << "Table Truncated Succesfully ! \n\n";
		else
			std::cout << Database::getInstance().getError() << "\n";*/
		break;
	default:
		std::cout << "Enter 1 or 2 only!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
}

void runSql() {
	int input;
	std::cout << "Enter 1 For Select type Query OR Enter 2 For others:";
	std::cin >> input;
	std::cout << std::endl;
	std::string sqlQuery;
	switch (input) {
	case 1:
		std::cout << "Enter sql query : ";
		std::cin.ignore();
		std::getline(std::cin, sqlQuery);
		std::cout << sqlQuery << std::endl;
		if (Database::getInstance().executeQueryCallback(sqlQuery))
			std::cout << "SQL Query Completed Successfully ! \n\n";
		else
			std::cout << Database::getInstance().getError() << "\n";
		break;
	case 2:
		std::cout << "Enter sql query : ";
		std::cin.ignore();
		std::getline(std::cin, sqlQuery);
		std::cout << sqlQuery << std::endl;
		if (Database::getInstance().executeQuery(sqlQuery))
			std::cout << "SQL Query Completed Successfully ! \n\n";
		else
			std::cout << Database::getInstance().getError() << "\n";
		break;
	default:
		std::cout << "Enter 1 or 2 only!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
}
void displayMenu() {
	bool flag = true;
	int choice;

	while (flag) {


		std::cout << "Welcome to the database management system!\n";
		std::cout << "Please select from below options to perform an action:\n";
		std::cout << "1. Create Table \n";
		std::cout << "2. Show Tables\n";
		std::cout << "3. Manipulate Existing Database\n";
		std::cout << "4. Delete Table\n";
		std::cout << "5. Run SQL Query\n";
		std::cout << "6. Backup Existing DB\n";
		std::cout << "7. Exit\n";
		std::cout << "Enter your choice (1-7): ";

		std::cin >> choice;
		std::cout << '\n';
		switch (choice) {
		case 1:
			createTable();
		break;
		case 2:
			showTable();
		break;
		case 3:
			manipulateDB();
			break;
		case 4:
			deleteTable();
		break;
		case 5:
			runSql();
		break;
		case 6:
			Database::getInstance().export_to_csv("Employee", "Employee.csv");
			Database::getInstance().export_to_csv("Engineer", "Engineer.csv");
			Database::getInstance().export_to_csv("Manager", "Manager.csv");
			Database::getInstance().export_to_csv("Salary", "Salary.csv");
			Database::getInstance().export_to_csv("Department", "Department.csv");
			std::cout << "All Tables Backed up successfully.\n";
			break;
		case 7:
			flag = false;
			break;
		default:
			std::cerr << "Invalid choice. Please enter a number between 1 and 6.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
}

