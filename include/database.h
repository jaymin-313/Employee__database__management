#pragma once
#include "../sqlite/sqlite3.h"
#include<string>
#include<vector>
#include "log.h"

using logs::Log;
class Database {
public:
    sqlite3* db{};

    bool open(std::string);
    bool createTables();
    std::string generateCreateTableQuery();
    void close();

    static Database& getInstance() {
        static Database DB;
        return DB;
    }

    bool executeQuery(const std::string& query);
    bool executeQueryCallback(const std::string& query);
    int getRow();
    std::string getError() const;
    void setError(const std::string& errorMessage);

    void export_to_csv(const std::string& table, const std::filesystem::path& filename);



    bool import_from_csv(const std::string& table, const std::string& filename);

   



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

};


