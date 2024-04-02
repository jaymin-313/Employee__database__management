#pragma once
#include<gtest/gtest.h>
#include "include/Engineer.h"

class engineerFixer : public testing::Test {
protected:
	void SetUp() override {
		Database::getInstance().open("employeeTest.db");
		Database::getInstance().createTables();
	}

	Employee e1{ 1001, "Jaymin", "Parmar", "02-02-2002", "1234567890", "jaymin.parmar@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2 };

	Engineer engineer1{ 1001, "J", "P", "02-02-2002", "1234567890", "j.p@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2 ,"test test","Test1"};

	Engineer engineer2{ 1001, "abc", "xyz", "02-02-2002", "1234567890", "abc.xyz@gmail.com",
		"wefwefcwef", "Male", "02-02-2024", "Office A", 1, 2  ,"test test","TestUpdated" };

	Salary salary1{ 1001,50000,10000 };

};