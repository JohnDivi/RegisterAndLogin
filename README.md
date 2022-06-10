# RegisterAndLogin

## Project Description
This project uses: classes, a database, and hashing to save and use user information for registering and logging in. Logging in allows the user to create "entries" which is similar to a journal. You may add, edit, and delete entries.

Currently, the program will be run on a CLI. In the future, I hope to implement this again with a GUI.


## Plans
_Note: finished plans will have a strike through ~~like this~~ followed by __DONE__ 


### Creating the Database class
The ***'Database'*** class will contain a single private variable containing all the user information.

Private variables:
- __'users'__ -> a map of usernames to hashed passwords

The ***'Database'*** class will contain these general functions:
- __'addUser(username, password)'__ -> returns void (adds a user to the map)
- __'updateUsers()'__ -> returns void (updates the file containing usernames and passwords)
- __'getUsernames()'__ -> returns a vector of strings containing usernames

The constructor will load the database.


### Creating the User class
The ***'User'*** class will contain 3 private.

Private variables:
- __'username'__ -> a user's username
- __'password'__ -> a user's hashed password
- __'entries'__ -> a vector containing the user's entries

The ***'User'*** class will contain these general functions:
- __'register(&database)'__ -> returns void (registers and adds user to the database)
- __'login(database)'__ -> returns void

#### register(&database)
- Ask user for a username and ensure that the chosen username does not exist. _Hint: Check a vector of existing usernames_
- Ask user for a password and ensure that the password is valid (password will require at least 1 capital letter and 1 symbol)
- Hash the password using SHA256 or others
- Store the username and hashed password into the database
- Update the database
- Notify user that the registration was successful and then return to the menu

#### login(database)
- Ask user for a username and password
- Verify that the username exists and matches the hashed password
- Notify user that the login was successful and show the logged-in menu

The constructor takes 2 parameters: __'username'__ and __'password'__ and will load the __'entries'__ using __'username'__.


### Running main()
- Load the database
- Main loop
