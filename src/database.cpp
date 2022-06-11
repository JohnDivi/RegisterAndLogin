#include "database.h"
#include <fstream>

Database::Database(std::string path) {
    std::ifstream userInfoFile(path);
    
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
