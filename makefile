o/database.o: src/database.cpp src/database.h
	g++ -c src/database.cpp -o o/database.o

o/menu.o: src/menu.cpp src/menu.h
	g++ -c src/menu.cpp -o o/menu.o

o/user.o: src/user.cpp src/user.h
	g++ -c src/user.cpp -o o/user.o -lcrypto

o/user-test.o: tests/user-test.cpp tests/test.h
	g++ -c tests/user-test.cpp -o o/user-test.o

o/database-test.o: tests/database-test.cpp tests/test.h
	g++ -c tests/database-test.cpp -o o/database-test.o

user-test: o/database.o o/menu.o o/user.o o/user-test.o
	g++ -o tests/program-user-test o/database.o o/menu.o o/user.o o/user-test.o 

database-test: o/database.o o/menu.o o/user.o o/database-test.o
	g++ -o tests/program-database-test o/database.o o/menu.o o/user.o o/database-test.o

tests: user-test database-test
	./tests/program-user-test
	./tests/program-database-test
