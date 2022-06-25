#ifndef MENU_H
#define MENU_H

#include <unordered_map>
#include <string>
#include <vector>

class Menu {

private:
    std::unordered_map<std::string, std::vector<std::string>> menus;

public:
    Menu() = default;
    int getMenuChoice(std::string menu);
    void addMenu(std::string menuName, std::vector<std::string> menuContent);
};

#endif
