#ifndef MENU_H
#define MENU_H

#include <unordered_map>
#include <string>

class Menu {

private:
    std::unordered_map<std::string, std::string> menus;

public:
    Menu();
    int getMenuChoice(std::string menu);

};

#endif
