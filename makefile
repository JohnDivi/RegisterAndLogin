CC = g++
CFLAGS = -Wall
SSLLIBS = -lssl -lcrypto

o/database.o: src/database.cpp src/database.h
	$(CC) $(CFLAGS) -c $< -o $@

o/menu.o: src/menu.cpp src/menu.h
	$(CC) $(CFLAGS) -c $< -o $@

o/user.o: src/user.cpp src/user.h
	$(CC) $(CFLAGS) -c $< -o $@

o/user-test.o: tests/user-test.cpp tests/test.h
	$(CC) $(CFLAGS) -c $< -o $@

o/database-test.o: tests/database-test.cpp tests/test.h
	$(CC) $(CFLAGS) -c $< -o $@

user-test: o/database.o o/menu.o o/user.o o/user-test.o
	$(CC) $(CFLAGS) -o tests/program-user-test $^ $(SSLLIBS)

database-test: o/database.o o/menu.o o/user.o o/database-test.o
	$(CC) $(CFLAGS) -o tests/program-database-test $^ $(SSLLIBS)

tests: database-test user-test
	./tests/program-database-test
	./tests/program-user-test
	
main-test: o/database.o o/menu.o o/user.o tests/main-test.cpp
	$(CC) $(CFLAGS) -o tests/main-test $^ $(SSLLIBS)
