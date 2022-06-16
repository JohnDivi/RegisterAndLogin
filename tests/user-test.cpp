#include "test.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Generate entries for usernames
void generateEntries(std::vector<std::string> usernames);


int main() {

	// Start tests
	std::cout
		<< "\n==================\n" 
		<< "START USER TESTING"
		<< "\n==================\n";

	Database database(USER_INFO);
	std::vector<User> users;
	std::vector<std::string> usernames = database.getUsernames();

	for (std::string username : usernames) {
		users.push_back(User(username, ENTRIES_DATA));
	}
	
	generateEntries(usernames);

	std::cout
		<< "\n================\n" 
		<< "END USER TESTING"
		<< "\n================\n";

	return 0;
}


void generateEntries(std::vector<std::string> usernames) {
	std::ofstream userEntriesFile;

	// Change this to pickEntriesAction(ENTRIES_ADD) once implemented
	for (std::string username : usernames) {
		userEntriesFile.open(ENTRIES_DATA + username + "-entries");

		if (!userEntriesFile.is_open()) {
			std::cerr << "Error opening entries file for " << username << "\n";
			exit(EXIT_FAILURE);
		}

		for (int i = 1; i <= 20; i++) {
			userEntriesFile << "Test entry " << i << "\n";
		}

		userEntriesFile.close();
	}

	return;
}
