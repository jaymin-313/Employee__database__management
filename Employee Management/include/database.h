#pragma once
#include "../sqlite/sqlite3.h"
#include<string>
#include<vector>
#include <filesystem>
#include "log.h"
#include<string>
#include <iostream>
#include <iomanip>
#include<sstream>

class Database {
public:
    sqlite3* db{};

    bool open(std::filesystem::path) ;
    bool createTables();
    void close();

    static Database& getInstance() {
        static Database DB;
        return DB;
    }

    bool executeQuery(const std::string& query);
    bool executeQueryCallback(const std::string& query,bool csv = true);
    int getRow() const;
    std::string getError() const;
    void setError(std::string& errorMessage);
    bool executeQueryRows(const std::string& query);
    void createTableQuery();
    void showTables();
    void deleteTableQuery();
    void userSqlQuery();
    bool checkExist(std::string table, int id);
    bool import_from_csv(const std::string& table, const std::string& filename);
    bool exportDatabase();
    bool export_to_csv(const std::string& table, const std::filesystem::path& filename);

private:
    Database() {}
    ~Database() {
        //sqlite3_close(db);
        close();
    }
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    std::string dbName{};
    std::string Error{};
    static int rows;
    static int callback(void* data, int argc, char** argv, char** azColName);
    static int callbackRows(void* data, int argc, char** argv, char** azColName);
    
};


