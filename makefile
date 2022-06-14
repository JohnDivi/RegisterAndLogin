o/database.o: src/database.cpp src/database.h
	g++ -c src/database.cpp -o o/database.o

o/menu.o: src/menu.cpp src/menu.h
	g++ -c src/menu.cpp -o o/menu.o

o/user.o: src/user.cpp src/user.h
	g++ -c src/user.cpp -o o/user.o

o/test-user.o: tests/test-user.cpp tests/test.h
	g++ -c tests/test-user.cpp -o o/test-user.o

o/test-database.o: tests/test-database.cpp tests/test.h
	g++ -c tests/test-database.cpp -o o/test-database.o

test-user: o/database.o o/menu.o o/user.o o/test-user.o
	g++ -o tests/test-program-user o/database.o o/menu.o o/user.o o/test-user.o 

test-database: o/database.o o/menu.o o/user.o o/test-database.o
	g++ -o tests/test-program-database o/database.o o/menu.o o/user.o o/test-database.o

tests: test-user test-database
	./tests/test-program-user
	./tests/test-program-database
