#include "database.h"
#include <fstream>
#include <iostream>

Database::Database(std::string path) {
    std::ifstream userInfoFile;
    userInfoFile.open(path);
    
    // Check if file opened
    if (!userInfoFile.is_open()) {
        exit(EXIT_FAILURE);
    }

    std::string username, password;

    while (userInfoFile >> username >> password) {
        users[username] = password;
    }

    userInfoFile.close();

}

std::vector<std::string> Database::getUsernames() {
    std::vector<std::string> usernames;

    for (auto pair : users) {
        usernames.push_back(pair.first);
    }

    return usernames;
}
