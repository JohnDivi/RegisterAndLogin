#ifndef USERS_H
#define USERS_H

#include "database.h"
#include <vector>
#include <string>

class User {

private:
    std::string username;
    std::vector<std::string> entries;

public:
    User(std::string username);
    void registerUser(Database& database);
    void loginUser(Database database);

};

#endif
