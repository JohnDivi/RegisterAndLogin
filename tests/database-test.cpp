#define USER_INFO "tests/test-data/test-user-info"
#define PASS "\u001b[32mPASS"
#define FAIL "\u001b[31mFAIL"
#define RESET "\u001b[0m"

#include "../src/database.h"
#include <fstream>
#include <iostream>
#include <algorithm>

int main() {
	Database database(USER_INFO);
	std::vector<std::string> usernames = database.getUsernames();
	std::string username;

	for (int i = 1; i < usernames.size() + 1; i++) {
		username = "testingUsername" + std::to_string(i);

		std::cout << "Test " + std::to_string(i) + "......";

		if (std::find(usernames.begin(), usernames.end(), username) != usernames.end()) {
			 std::cout << PASS << RESET << '\n';
		}

		else {
			std::cout << FAIL << RESET << '\n';
		}
	}

	return 0;
}


