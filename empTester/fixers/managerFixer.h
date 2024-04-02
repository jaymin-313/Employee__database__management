#pragma once
#include<gtest/gtest.h>
#include "include/Manager.h"

class managerFixer : public testing::Test {
protected:
	void SetUp() override {
		Database::getInstance().open("employeeTest.db");
		Database::getInstance().createTables();
	}

	Employee e1{ 1001, "Jaymin", "Parmar", "02-02-2002", "1234567890", "jaymin.parmar@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2 };

	Manager manager1{ 1001, "J", "P", "02-02-2002", "1234567890", "j.p@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2  ,3,"TitleTest" };

	Manager manager2{ 1001, "abc", "xyz", "02-02-2002", "1234567890", "abc.xyz@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2  ,3,"TitleTestUpdated" };

	Salary salary1{ 1001,50000,10000 };

};