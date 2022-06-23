#define USER_PATH "tests/data-test/user-info-test"
#define ENTRIES_PATH "tests/data-test/user-entries-test"

#include <iostream>

#include "../src/database.h"
#include "../src/menu.h"
#include "../src/user.h"

int main() {
	Database database(USER_PATH);
	User myUser(ENTRIES_PATH);

	if (myUser.loginUser(database)) {
		myUser.pickEntriesAction(User::eEntriesEdit);
		myUser.pickEntriesAction(User::eEntriesSave);
	}
	else {
		std::cout << "User doesn't exist\n";
	}

	return 0;
}
