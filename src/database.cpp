#include "../include/database.h"
#include<string>
#include <vector>
#include <iostream>
#include <iomanip>

int Database::rows = 0;
bool Database::open(std::string db_name) {
    if (sqlite3_open(db_name.c_str(), &db) == SQLITE_OK) {

        if (!createTables()) {
            return false;
        }

      /*  std::string pragmaQuery = { "PRAGMA foreign_keys = ON;" };
        executeQuery(pragmaQuery);*/

        //std::cout << "Opened\n";
        return true;
    }
    else {
        setError("Failed to open database");
        return false;
    }
}

bool Database::createTables() {

    const char* sql = "CREATE TABLE IF NOT EXISTS Employee ("
        "id INTEGER PRIMARY KEY,"
        "firstname VARCHAR,"
        "lastname VARCHAR,"
        "dob DATE,"
        "mobile VARCHAR,"
        "email VARCHAR,"
        "address VARCHAR,"
        "gender VARCHAR CHECK (gender IN ('Male', 'Female', 'Other')),"
        "doj DATE,"
        "w_location VARCHAR,"
        "manager_id INTEGER,"
        "department_id INTEGER,"
        "FOREIGN KEY (department_id) REFERENCES Department(id),"
        "FOREIGN KEY (manager_id) REFERENCES Employee(id));";

    if (!executeQuery(sql))
    {
        return false;
    }

    const char* sql2 = "CREATE TABLE IF NOT EXISTS Department ("
        "id INTEGER PRIMARY KEY,"
        "name VARCHAR,"
        "manager_id INTEGER,"
        "description VARCHAR,"
        "FOREIGN KEY (manager_id) REFERENCES Employee(id))";


    if (!executeQuery(sql2))
    {
        return false;
    }



    const char* sql3 = "CREATE TABLE IF NOT EXISTS Engineer ("
        "id INTEGER PRIMARY KEY,"
        "programming_language VARCHAR,"
        "specialization VARCHAR,"
        "FOREIGN KEY (id) REFERENCES Employee(id))";

    if (!executeQuery(sql3))
    {
        return false;
    }


    const char* sql4 = "CREATE TABLE IF NOT EXISTS Manager ("
        "id INTEGER PRIMARY KEY,"
        "management_experience INTEGER,"
        "project_title VARCHAR,"
        "FOREIGN KEY (id) REFERENCES Employee(id))";


    if (!executeQuery(sql4))
    {
        return false;
    }


    const char* sql5 = "CREATE TABLE IF NOT EXISTS Salary ("
        "id INTEGER PRIMARY KEY,"
        "amount INTEGER,"
        "base_salary INTEGER,"
        "bonus INTEGER,"
        "FOREIGN KEY (id) REFERENCES Employee(id))";

    if (!executeQuery(sql5))
    {
        return false;
    }


    return true;
}

std::string Database::generateCreateTableQuery() {
    std::string tableName;
    std::cout << "Enter table name: ";
    std::cin >> tableName;

    std::string sql = "CREATE TABLE IF NOT EXISTS " + tableName + " (";
    std::vector<std::string> columns;

    // Input column details from the user
    char choice;
    do {
        std::string columnName, columnType, constraints;
        std::cout << "Enter column name: ";
        std::cin >> columnName;
        std::cout << "Enter column type: ";
        std::cin >> columnType;

        // Input constraints (if any)
        std::cout << "Enter column constraints (e.g., PRIMARY KEY, FOREIGN KEY): ";
        std::cin.ignore();
        std::getline(std::cin, constraints);

        // Append column name, type, and constraints to the SQL query
        columns.push_back(columnName + " " + columnType + " " + constraints);

        std::cout << "Add another column? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Concatenate column details to form the final SQL query
    for (size_t i = 0; i < columns.size(); ++i) {
        sql += columns[i];
        if (i < columns.size() - 1) {
            sql += ",";
        }
    }
    sql += ");";

    return sql;
}

void Database::close() {
    if (db) {
        //std::cout << "sqlite3 closed\n";
        sqlite3_close(db);
        db = nullptr;
    }
}

bool Database::executeQuery(const std::string& query) {
    char* errMsg = nullptr;


    int rc = sqlite3_exec(db, query.c_str(), NULL, 0, &errMsg);

    if (rc != SQLITE_OK) {
        setError(errMsg);
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}

std::string Database::getError() const {
    return Error;
}

bool Database::executeQueryCallback(const std::string& query) {
    char* errMsg = nullptr;
    
    int rc = sqlite3_exec(db, query.c_str(), callback, 0, &errMsg);
    std::cout << rows << " rows returned \n\n";
    rows = 0;
    if (rc != SQLITE_OK) {
        setError(errMsg);
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
int Database::getRow() {
    return rows;
}

int Database::callback(void* data, int argc, char** argv, char** azColName) {
    ++rows;
    int colWidth = 22;
    int length;
    std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < argc; ++i) {
        length = strlen(azColName[i]) - 2;
        std::cout << " " << azColName[i] << std::setw(colWidth - length) << ": " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "----------------------------------------" << std::endl;
    return 0;
}

void Database::setError(const std::string& errorMessage) {
    Error = errorMessage;
}