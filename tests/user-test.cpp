#include "test.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// Generate entries for usernames
void generateEntries(std::vector<std::string> usernames);


int main() {

	// Get test usernames
	Database usernamesDatabase(USER_INFO);
	std::vector<std::string> testNames = usernamesDatabase.getUsernames();

	// Empty USER_INFO for testing
	std::ofstream empty(USER_INFO);
	if (!empty.is_open()) {
		std::cerr << "Failed to open user info\n";
		exit(EXIT_FAILURE);
	}
	empty.close();

	// Start tests
	std::cout
		<< "\n==================\n" 
		<< "START USER TESTING"
		<< "\n==================\n";

	Database database(USER_INFO);

	std::vector<User> users;
	std::vector<std::string> usernames = database.getUsernames();

	// Registration test
	std::string userAndPass = "";
	bool bRegisterSuccess = true;
	for (std::string username : testNames) {
		User user(ENTRIES_DATA);
		userAndPass += username + '\n';
		userAndPass += username + "&Password\n";

		std::istringstream input(userAndPass);
		if (!user.registerUser(database, input)) bRegisterSuccess = false;
		userAndPass = "";
		
		// Put created user in vector
		users.push_back(user);
	}
	if (bRegisterSuccess) std::cout << "\nRegistration test......" << PASS << RESET << '\n';
	else std::cout << "\nRegistration test......" << FAIL << RESET << '\n';
	
	generateEntries(testNames);

	// Login test
	bool bLoginSuccess = true;
	userAndPass = "";
	for (size_t i = 0; i < testNames.size(); i++) {
		userAndPass += testNames[i] + '\n';
		userAndPass += testNames[i] + "&Password\n";
		std::istringstream input(userAndPass);
		if (!users[i].loginUser(database, input)) bLoginSuccess = false;
		userAndPass = "";
	}
	if (bLoginSuccess) std::cout << "\nLogin test......" << PASS << RESET << '\n';
	else std::cout << "\nLogin test......" << FAIL << RESET << '\n';

	//users[0].pickEntriesAction(User::eEntriesView);

	std::cout
		<< "\n================\n" 
		<< "END USER TESTING"
		<< "\n================\n";

	return 0;
}


void generateEntries(std::vector<std::string> usernames) {
	std::ofstream userEntriesFile;

	// Change this to pickEntriesAction(eEntriesAdd) once implemented
	for (std::string username : usernames) {
		std::string userEntriesPath = std::string("/") + username + "-entries";

		userEntriesFile.open(ENTRIES_DATA + userEntriesPath);

		if (!userEntriesFile.is_open()) {
			std::cerr << "Error opening entries file for " << username << "\n";
			exit(EXIT_FAILURE);
		}

		for (int i = 1; i <= 20; i++) {
			userEntriesFile << "Test entry " << i << '\n';
		}

		userEntriesFile.close();
	}

	return;
}
