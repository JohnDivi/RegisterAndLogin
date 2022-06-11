# RegisterAndLogin

## Project Description
This project uses: classes, a database, and hashing to save and use user information for registering and logging in. Logging in allows the user to create "entries" which is similar to a journal. You may add, edit, and delete entries.

Currently, the program will be run on a CLI. I am looking forward to implementing this with a GUI in the future.


## Planning
_Note: finished plans will have a strikethrough ~~like this~~ followed by __DONE___


### Creating the Database class
The ***Database*** class will contain a single private variable containing all the user information.

Private variables:
- __'users'__ -> a map of usernames to hashed passwords

The ***Database*** class will contain these general functions:
- __addUser(username, password)__ -> returns void (adds a user to the map)
- __updateDBFile()__ -> returns void (updates the file containing usernames and passwords)
- __getUsernames()__ -> returns a vector of strings containing usernames

#### addUser(username, password)
- Adds a user to the map

#### updateDBFile()
- Updates the database file

#### getUsernames()
- Goes through the map's usernames 
- Returns a vector of usernames

The constructor will load the database.


### Creating the User class
The ***User*** class will contain 2 private variables.

Private variables:
- __'username'__ -> a user's username
- __'entries'__ -> a vector containing the user's entries

The ***User*** class will contain these general functions:
- __registerUser(&database)__ -> returns void (registers and adds user to the database)
- __loginUser(database)__ -> returns void

#### registerUser(&database)
- Ask user for a username and ensure that the chosen username does not exist. _Hint: Check a vector of existing usernames_
- Ask user for a password and ensure that the password is valid (password will require at least 1 capital letter and 1 symbol)
- Hash the password using SHA256 or others
- Store the username and hashed password into the database
- Update the database
- Notify user that the registration was successful and then return to the menu

#### loginUser(database)
- Ask user for a username and password
- Verify that the username exists and matches the hashed password (checks database)
- Notify user that the login was successful and show the logged-in menu

The constructor takes 1 parameter: __'username'__ and will load the __'entries'__ using __'username'__.


### Creating the Menu class
The ***Menu*** class will automatically create menus, needing two private variables.

Private variables:
- __'content'__ -> the menu's content, a vector of strings
- __'otherMenus'__ -> a vector of menus available to current menu

The ***Menu*** class will contain these general functions:
- __updateMenuTitle(title)__ -> returns void, updates __'content's'__ first index
- __updateMenuChoice(choice, details)__ -> returns void, updates __'content's'__ __choice__ index
- __showMenu()__ -> returns void, goes through __'content'__ and outputs formatted elements
- __getMenu(choice)__ -> returns __'otherMenus[choice]'__

#### updateMenuTitle(title)
- Sets __'content[0]'__ to __title__

#### updateMenuChoice(choice, details)
- Error check if __choice__ > size of __'content'__
- Sets __'content[choice]'__ to __details__

#### showMenu()
- Shows formatted __'content'__

#### getChoice(choice)
- Error check if __choice__ > size of __'otherMenus'__
- Return chosen menu

The contructor takes 1 parameter: __'menuSize'__, which is the length of __title__ + __'content'__


### Running main()
- Load the database
- Setup menus
- Main loop
