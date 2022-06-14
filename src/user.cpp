#include "user.h"
#include <fstream>
#include <iostream>

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
