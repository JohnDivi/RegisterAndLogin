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

~~#### getUsernames()~~ __DONE__
- ~~Goes through the map's usernames~~
- ~~Returns a vector of usernames~~

~~The constructor will load the database taking in the path for user info.~~ __DONE__


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
The ***Menu*** class contains all menus.

Private variables:
- __'menus'__ -> unordered map containing type of menu as a key and its contents as values

The ***Menu*** class will contain these general functions:
- __getMenuChoice(menu)__ -> returns user choice (int)

#### getMenuChoice(menu)
- Show menu passed in argument
- Gets number input from user and return

The constructor sets up all possible menus and adds it to the __'menus'__ map


### Running main()
- Load the database
- Setup menus
- Main loop
