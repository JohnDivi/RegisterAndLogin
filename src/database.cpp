#include "database.h"
#include <fstream>
#include <iostream>
#include <unordered_map>

Database::Database(std::string path) {
    this->path = path;

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

bool Database::checkCorrectDetails(std::string username, std::string password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

void Database::updateDBFile() {
    std::ofstream userInfoFile;
    userInfoFile.open(path);

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
