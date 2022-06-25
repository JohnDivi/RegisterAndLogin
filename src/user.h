#ifndef USERS_H
#define USERS_H

#include "database.h"
#include <vector>
#include <string>
#include <iostream>

class User {

private:
    std::string username;
    std::string entriesPath;
    std::vector<std::string> entries;

public:
    User(std::string entriesPath);
    bool registerUser(Database& database, std::istream& stream = std::cin);
    bool loginUser(Database database, std::istream& stream = std::cin);

    // Actions for pickEntriesAction()
    enum entriesAction {
        eEntriesView,
        eEntriesEdit,
        eEntriesAdd,
        eEntriesDelete,
        eEntriesSave,
        eEntriesLogout
    };
    void pickEntriesAction(int action, std::istream& stream = std::cin);

};

#endif
