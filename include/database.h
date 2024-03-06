#pragma once
#include "../sqlite/sqlite3.h"
#include<string>
#include<vector>

class Database {
public:
    sqlite3* db;
    Database() = default;
    Database(const std::string& db) :dbName(db) {}

    ~Database() {
        close();
    }

    bool open();
    bool createTables();
    void close();

    bool executeQuery(const std::string& query);
    bool executeQueryCallback(const std::string& query);
    std::string getError() const;
    void setError(const std::string& errorMessage);

private:
    /*sqlite3* db;*/
    std::string dbName{};
    std::string Error{};
    static int rows;
    static int callback(void* data, int argc, char** argv, char** azColName);
    
};


