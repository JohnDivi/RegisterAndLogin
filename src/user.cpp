#define ENTRIES_DATA "data/user-entries/"

#include "users.h"
#include <fstream>
#include <iostream>

User::User(std::string username) {
    std::ifstream userEntriesFile;
    userEntriesFile.open(ENTRIES_DATA + username);

    if (!userEntriesFile.is_open()) {
        std::cerr << "Entries file not found\n";
        exit(EXIT_FAILURE);
    }

    userEntriesFile.close();

}
