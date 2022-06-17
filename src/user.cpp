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
    std::ofstream createFile(entriesPath + username + "-entries");
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

    if (database.checkCorrectDetails(username, password)) {
        std::ifstream entriesFile(entriesPath + "/" + username + "-entries");

        if (!entriesFile.is_open()) {
            std::cerr << "Failed opening entries file for " << username << '\n';
            exit(EXIT_FAILURE);
        }

        std::string entriesBuffer;
        while (entriesFile >> entriesBuffer) {
            entries.push_back(entriesBuffer);
        }
        entriesFile.close();
        return true;
    }
    return false;
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
