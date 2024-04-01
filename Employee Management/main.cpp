#include <conio.h>
#include <iostream>
#include<filesystem>
#include "include/database.h"
#include "include/askPrompt.h"
#include "include/log.h"
#include "include/auth.h"

using logs::Log;

int main() {

	if (Auth::authUser()) {

		std::filesystem::path dbPath = "employee.db";
		if (!Database::getInstance().open(dbPath)) {
			std::cerr << "Error opening database: " << Database::getInstance().getError() << "\n";
			return 1;
		}
		else {
			Log::getInstance().Info("Database Opened.");
		}
		system("cls");
		askPromptMain();
		Database::getInstance().close();

	}
	return 0;

}

