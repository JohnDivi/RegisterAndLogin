#include "menu.h"

#include <iostream>
#include <string>

int Menu::getMenuChoice(std::string menu) {

	if (menus.find(menu) == menus.end()) {
		std::cout << "Menu not found!\n";
		exit(EXIT_FAILURE);
	}

	std::string choiceBuffer;
	unsigned choice;

	do {
		for (std::string content : menus[menu]) {
			std::cout << content;
		}
		std::cout << "\nEnter choice: ";
		std::getline(std::cin, choiceBuffer);

		choice = std::stoi(choiceBuffer);

		if (choice >= menus[menu].size()) {
			std::cout << "Not a valid choice!\n";
		}

	} while (choice >= menus[menu].size());

	return choice;
}

void Menu::addMenu(std::string menuName, std::vector<std::string> menuContent) {
	menus[menuName] = menuContent;
}
