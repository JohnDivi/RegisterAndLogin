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
    User(std::string username, std::string entriesPath);
    bool registerUser(Database& database);
    bool loginUser(Database database);

    // Actions for pickEntriesAction()
    enum entriesAction {
        eEntriesView,
        eEntriesEdit,
        eEntriesAdd,
        eEntriesDelete,
        eEntriesSave
    };
    void pickEntriesAction(int action);

};

#endif
