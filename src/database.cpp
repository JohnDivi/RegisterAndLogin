#include "database.h"
#include <fstream>
#include <iostream>

Database::Database(std::string path) {
    std::ifstream userInfoFile;
    userInfoFile.open(path);
    
    // Check if file opened successfully
    if (!userInfoFile.is_open()) {
        std::cerr << "Failed to open path\n";
        exit(EXIT_FAILURE);
    }

    std::string username, password;

    while (userInfoFile >> username >> password) {
        users[username] = password;
    }

    userInfoFile.close();

}

void Database::addUser(std::string username, std::string password) {
    users[username] = password;
    return;
}

void Database::updateDBFile(std::string path) {
    std::ofstream userInfoFile;

    // Check if file opened successfully
    if (!userInfoFile.is_open()) {
        std::cerr << "Failed to open path\n";
        exit(EXIT_FAILURE);
    }

    for (auto pair : users) {
        userInfoFile << pair.first << " " << pair.second << "\n";
    }

    userInfoFile.close();
    return;
}

std::vector<std::string> Database::getUsernames() {
    std::vector<std::string> usernames;

    for (auto pair : users) {
        usernames.push_back(pair.first);
    }

    return usernames;
}
