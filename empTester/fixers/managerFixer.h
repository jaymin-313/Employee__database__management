#pragma once
#include<gtest/gtest.h>
#include "include/Manager.h"

class managerFixer : public testing::Test {
protected:
	void SetUp() override {
		Database::getInstance().open("employeeTest.db");
		Database::getInstance().createTables();
	}

	Employee e1{ 1001, "Zeal", "Shah", "02-02-2002", "1234567890", "zeal.shah@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2 };

	Manager manager1{ 1001, "Zeal", "Shah", "02-02-2002", "1234567890", "zeal.shah@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2  ,3,"TitleTest" };

	Manager manager2{ 1001, "Zeal", "Shah", "02-02-2002", "1234567890", "zeal.shah@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2  ,3,"TitleTestUpdated" };

	Salary salary1{ 1001,50000,10000 };

};