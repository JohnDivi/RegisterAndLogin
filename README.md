# RegisterAndLogin

## Project Description
This project uses: classes, a database, and hashing to save and use user information for registering and logging in. Logging in allows the user to create "entries" which is similar to a journal. You may add, edit, and delete entries.

Currently, the program will be run on a CLI. I am looking forward to implementing this with a GUI in the future.

## To do tests
- Call "make tests" in terminal


## Planning
_Note: finished plans will have a strikethrough ~~like this~~ followed by __DONE___


### Creating the Database class
The ***Database*** class will contain a single private variable containing all the user information.

Private variables:
- __'users'__ -> a map of usernames to hashed passwords

The ***Database*** class will contain these general functions:
- __addUser(username, password)__ -> returns void (adds a user to the map)
- __checkCorrectDetails(username, password)__ -> returns bool
- __updateDBFile(path)__ -> returns void (updates the file containing usernames and passwords)
- __getUsernames()__ -> returns a vector of strings containing usernames

#### ~~addUser(username, password)~~ __DONE__
- Adds a user to the map

#### ~~checkCorrectDetails(username, password)~~ __DONE__
- Check if username and password matches the one in the map

#### ~~updateDBFile(path)~~ __DONE__
- Updates the database file in the specified path

#### ~~getUsernames()~~ __DONE__
- Goes through the map's usernames
- Returns a vector of usernames

~~The constructor will load the database taking in the path for user info.~~ __DONE__


### Creating the User class
The ***User*** class will contain 2 private variables.

Private variables:
- __'entriesPath'__ -> contains the entries path
- __'entries'__ -> a vector containing the user's entries

The ***User*** class will contain these general functions:
- __registerUser(&database, stream)__ -> returns __true__ if done or __false__ if fail
- __loginUser(database, stream)__ -> returns __true__ if done or __false__ if fail
- __pickEntriesAction(action)__ -> returns void

#### ~~registerUser(&database, stream)~~ __DONE__
- ~~Ask user for a username from __stream__ and ensure that the chosen username does not exist. _Hint: Check a vector of existing usernames_
- Ask user for a password from __stream__ and ensure that the password is valid (password will require at least 1 capital letter and 1 symbol)
- Hash the password using SHA256 or others
- Create an entries file for the user
- Store the username and hashed password into the database
- Update the database
- Notify user that the registration was successful and then return to the menu

#### ~~loginUser(database, stream)~~ __DONE__
- Ask user for a username and password from __stream__
- Verify that the username exists and matches the hashed password (checks database)
- Notify user that the login was successful
- Load entries of user
- Show logged in menu

#### pickEntriesAction(action)
- Ask user for action: ~~view~~, edit, add, delete, and save entries.

~~The constructor sets the entries path of users~~ __DONE__


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
