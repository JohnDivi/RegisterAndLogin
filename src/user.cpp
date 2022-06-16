#include "user.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>


// Helper functions
bool verifyUsername(std::string username, std::vector<std::string> existingUsernames);
bool verifyPassword(std::string password);


User::User(std::string username, std::string entriesPath) {
    std::ifstream userEntriesFile;
    userEntriesFile.open(entriesPath + username + "-entries");

    // Entries file did not exist -> new user. Create an entries file for them
    if (!userEntriesFile.is_open()) {
        std::cout << "Entries file for " << username << " not found. Creating. Re-run program.\n";
        std::ofstream createFile(entriesPath + username + "-entries");
        if (!createFile.is_open()) {
            std::cerr << "Error creating entries file for " << username << "\n";
            exit(EXIT_FAILURE);
        }
        createFile.close();

        // Re-open after creating file
        userEntriesFile.open(entriesPath + username + "-entries");

        // Unkown error at this point
        if (!userEntriesFile.is_open()) {
            std::cerr << "Error opening entries file for " << username << "\n";
            exit(EXIT_FAILURE);
        }
    }

    // Fill up entries
    std::string entryBuffer;
    while (std::getline(userEntriesFile, entryBuffer)) {
        entries.push_back(entryBuffer);
    }

    userEntriesFile.close();
}

bool User::registerUser(Database& database) {
    std::vector<std::string> existingUsernames = database.getUsernames();
    std::string username, password;

    std::cout << "Username: ";
    std::getline(std::cin, username);
    if (!verifyUsername(username, existingUsernames)) return false;

    std::cout << "Password: ";
    std::getline(std::cin, password);
    if (!verifyPassword(password)) return false;

    // Hash password here


    return true;
}

// Checks if username has no spaces and does not already exist
bool verifyUsername(std::string username, std::vector<std::string> existingUsernames) {
    
    // Username already exists
    if (std::find(existingUsernames.begin(), existingUsernames.end(), username)
        == existingUsernames.end()) {
        return false;
    }

    // Username contains space
    for (char c : username) {
        if (c == ' ') {
            return false;
        }
    }

    return true;
}

// Checks if password is valid: 1 capital letter and 1 symbol
bool verifyPassword(std::string password) {
    bool bCapital = false, bSymbol = false;

    for (char c : password) {
        if (std::isupper(c)) bCapital = true;
        if (!std::isalpha(c) && !std::isdigit(c)) bSymbol = true;
    }

    if (!bCapital || !bSymbol) {
        return false;
    }

    return true;
}
