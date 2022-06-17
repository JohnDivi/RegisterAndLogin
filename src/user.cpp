#include "user.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>


// Helper functions
bool verifyUsername(std::string username, std::vector<std::string> existingUsernames);
bool verifyPassword(std::string password);
bool getUserAndPass(std::string& username, std::string& password,
    std::istream& stream, std::vector<std::string> existingUsernames);
void viewEntries(std::vector<std::string>& entries);
void editEntries(std::vector<std::string>& entries);
void addEntries(std::vector<std::string>& entries);
void deleteEntries(std::vector<std::string>& entries);
void saveEntries(std::vector<std::string>& entries, std::string path);
std::string getSHA256(std::string input);


User::User(std::string entriesPath) {
    this->entriesPath = entriesPath;
}

bool User::registerUser(Database& database, std::istream& stream = std::cin) {
    std::vector<std::string> existingUsernames = database.getUsernames();
    std::string username, password;

    // Get the user and pass here
    if (!getUserAndPass(username, password, stream, existingUsernames)) return false;

    // Hash password here, only use first 64 characters
    password = getSHA256(password).substr(0, 64);

    // Create an entries file for the user
    std::string filePath = entriesPath + "/" + username + "-entries";
    std::ofstream createFile(filePath);
    if (!createFile.is_open()) {
        std::cerr << "Error creating entries file for " << username << "\n";
        exit(EXIT_FAILURE);
    }
    createFile.close();

    database.addUser(username, password);
    database.updateDBFile();

    return true;
}

bool User::loginUser(Database database, std::istream& stream = std::cin) {
    std::string username, password;
    std::vector<std::string> existingUsernames;

    // Get the user and pass here
    if (!getUserAndPass(username, password, stream, existingUsernames)) return false;

    // Hash password here, only use first 64 characters
    password = getSHA256(password).substr(0, 64);

    // Username doesn't exist or password doesn't match username
    if (!database.checkCorrectDetails(username, password)) return false;

    // Login success, open entries and load
    std::string filePath = entriesPath + "/" + username + "-entries";
    std::ifstream entriesFile(filePath);
    if (!entriesFile.is_open()) {
        std::cerr << "Failed opening entries file for " << username << '\n';
        exit(EXIT_FAILURE);
    }

    std::string entriesBuffer;
    while (std::getline(entriesFile, entriesBuffer)) {
        entries.push_back(entriesBuffer);
    }
    entriesFile.close();
    return true;
}

void User::pickEntriesAction(int action) {
    switch (action) {
        case eEntriesView:
            viewEntries(entries);
            break;
        case eEntriesEdit:
            editEntries(entries);
            break;
        case eEntriesAdd:
            addEntries(entries);
            break;
        case eEntriesDelete:
            deleteEntries(entries);
            break;
        case eEntriesSave:
            saveEntries(entries, entriesPath);
            break;
        default: 
            std::cerr << "Invalid option\n";
            break;
    }
}

// Checks if username has no spaces and does not already exist
bool verifyUsername(std::string username, std::vector<std::string> existingUsernames) {
    
    // Username already exists
    if (std::find(existingUsernames.begin(), existingUsernames.end(), username)
        != existingUsernames.end()) {
        std::cerr << "Username already exists!\n";
        return false;
    }

    // Username contains space
    for (char c : username) {
        if (c == ' ') {
            std::cerr << "Username contains a space!\n";
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
        std::cerr << "Password must have 1 capital letter and 1 symbol!\n";
        return false;
    }

    return true;
}

// Gets the username and password
bool getUserAndPass(std::string& username, std::string& password,
    std::istream& stream, std::vector<std::string> existingUsernames) {
    if (&stream == &std::cin) std::cout << "Username: ";
    std::getline(stream, username);
    if (!verifyUsername(username, existingUsernames)) return false;

    if (&stream == &std::cin) std::cout << "Password: ";
    std::getline(stream, password);
    if (!verifyPassword(password)) return false;

    return true;
}

// Views entries given the vector
void viewEntries(std::vector<std::string>& entries) {
    std::cout << "Here are your entries:\n";
    for (int i = 1; i <= entries.size(); i++) {

        std::cout << '\n' << std::to_string(i);
        for (int j = 0; j < 6 - std::to_string(i).size(); j++) {
            std::cout << ".";
        }
        std::cout << entries[i-1] << '\n';
    }
    return;
}

// Edits user chosen entries
void editEntries(std::vector<std::string>& entries) {

}

// Adds entries
void addEntries(std::vector<std::string>& entries) {

}

// Deletes entries
void deleteEntries(std::vector<std::string>& entries) {

}

// Saves entries
void saveEntries(std::vector<std::string>& entries, std::string path) {

}

// Generates a SHA256 hash
std::string getSHA256(std::string input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);
    std::stringstream stream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        stream << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return stream.str();

}
