#define USER_INFO "data/user-info"

#include "database.h"
#include <fstream>

Database::Database() {
    std::ifstream userInfoFile(USER_INFO);
    
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
