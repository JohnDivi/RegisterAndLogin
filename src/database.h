#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include <vector>
#include <string>

class Database {

    private:
        std::unordered_map<std::string, std::string> users;

    public:
        Database();
        void addUser(std::string username, std::string password);
        void updateDBFile();
        std::vector<std::string> getUsernames();

}

#endif
