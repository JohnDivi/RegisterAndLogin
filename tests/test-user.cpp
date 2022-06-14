#include "test.h"

int main() {

	Database database(USER_INFO);
	std::vector<User> users;

	for (std::string username : database.getUsernames()) {
		users.push_back(User(username, ENTRIES_DATA));
	}
	
	return 0;
}
