#include "test.h"

#include <fstream>
#include <iostream>
#include <algorithm>


// Tests if testingUsernameN exists, 1 <= N <= end
void testUsernameDatabase(std::vector<std::string> usernames, int end);

// Tests if adding usernames N times work, start <= N <= amount
void testAddUsername(Database& database, int start, int amount);

// Resets the test-user-info file for accurate testing
void resetTestFile();


int main() {
	// Reset test file
	resetTestFile();

	// Start tests
	std::cout
		<< "\n======================\n" 
		<< "START DATABASE TESTING"
		<< "\n======================\n";

	Database database(USER_INFO);
	std::vector<std::string> usernames;

	// Test if usernames exist 1-10
	std::cout << "\nNormal database test\n";
	usernames = database.getUsernames();
	testUsernameDatabase(usernames, 10);

	// Test if adding usernames work
	std::cout << "\nAdding usernames test\n";
	testAddUsername(database, 11, 20);
	usernames = database.getUsernames();
	testUsernameDatabase(usernames, 20);

	database.updateDBFile(USER_INFO);

	// Test if reloading database keeps the new usernames
	std::cout << "\nReloading database test\n";
	Database reloadedDatabase(USER_INFO);
	usernames = reloadedDatabase.getUsernames();
	testUsernameDatabase(usernames, 20);

	std::cout
		<< "\n====================\n" 
		<< "END DATABASE TESTING"
		<< "\n====================\n";

	return 0;
}

void testUsernameDatabase(std::vector<std::string> usernames, int end) {
	std::string username;

	for (int i = 1; i <= end; i++) {
		username = "testingUsername" + std::to_string(i);

		std::cout << "Test " + std::to_string(i) + "......";

		if (std::find(usernames.begin(), usernames.end(), username) != usernames.end()) {
			std::cout << PASS << RESET << '\n';
		}

		else {
			std::cout << FAIL << RESET << '\n';
		}
	}

	return;
}

void testAddUsername(Database& database, int start, int amount) {

	for (int i = start; i <= amount; i++) {
		database.addUser("testingUsername" + std::to_string(i),
			"randomPassword" + std::to_string(i));
	}

	return;
}

void resetTestFile() {
	std::ofstream testFile;
	testFile.open(USER_INFO);

	if (!testFile.is_open()) {
		std::cerr << "Failed opening file\n";
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i <= 10; i++) {
		testFile << "testingUsername" + std::to_string(i) + " randomPassword" +
			std::to_string(i) + "\n";
	}
	testFile.close();
	return;
}
