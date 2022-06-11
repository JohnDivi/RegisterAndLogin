#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

class Menu {

    private:
        std::vector<std::string> content;
        std::vector<Menu> otherMenus;

    public:
        Menu(int menuSize);
        void updateMenuTitle(std::string title);
        void updateMenuChoice(int choice, std::string details);
        void showMenu();
        Menu getMenu(int choice);

}

#endif
