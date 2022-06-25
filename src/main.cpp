#define ENTRIES_DATA "src/data/user-entries"
#define USER_INFO "src/data/user-info"

#include "database.h"
#include "user.h"
#include "menu.h"

#include <iostream>
#include <string>
#include <vector>

std::string makeWelcomeMenu(Menu& menus);
std::string makeLoggedInMenu(Menu& menus);

int main() {

	// Load database
	Database database(USER_INFO);

	// Setup menus
	Menu menus;
	std::string welcomeMenu = makeWelcomeMenu(menus);
	std::string loggedInMenu = makeLoggedInMenu(menus);

	// Create User
	User user(ENTRIES_DATA);

	int menuChoice = 0;
	while (menuChoice != -1) {
		menuChoice = menus.getMenuChoice(welcomeMenu);

		// Welcome menu:
		// 0: Register
		// 1: Login
		// 2: Exit

		if (menuChoice == 0) {
			user.registerUser(database);
		}

		else if (menuChoice == 1) {
			user.loginUser(database);

			do {
				menuChoice = menus.getMenuChoice(loggedInMenu);

				if (menuChoice == User::eEntriesLogout) {
					menuChoice = -1;
					continue;
				}

				user.pickEntriesAction(menuChoice);

			} while (menuChoice != -1);
		}

		else if (menuChoice == 2) {
			menuChoice = -1;
		}
	}

	return 0;
}

std::string makeWelcomeMenu(Menu& menus) {
	std::string menuName;
	std::vector<std::string> menuContents;

	menuName = "welcomeMenu";
	menuContents.push_back("0 -> Register\n");
	menuContents.push_back("1 -> Login\n");
	menuContents.push_back("2 -> Exit\n");
	menus.addMenu(menuName, menuContents);

	return menuName;
}

std::string makeLoggedInMenu(Menu& menus) {
	std::string menuName;
	std::vector<std::string> menuContents;

	menuName = "loggedInMenu";
	menuContents.push_back("0 -> View Entries\n");
	menuContents.push_back("1 -> Edit Entries\n");
	menuContents.push_back("2 -> Add Entries\n");
	menuContents.push_back("3 -> Delete Entries\n");
	menuContents.push_back("4 -> Save Entries\n");
	menuContents.push_back("5 -> Logout\n");
	menus.addMenu(menuName, menuContents);

	return menuName;
}
