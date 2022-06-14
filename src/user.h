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
    void registerUser(Database& database);
    void loginUser(Database database);

    // Actions for pickEntriesAction()
    enum entriesAction {
        ENTRIES_VIEW,
        ENTRIES_EDIT,
        ENTRIES_ADD,
        ENTRIES_DELETE,
        ENTRIES_SAVE
    };
    void pickEntriesAction(int action);

};

#endif
