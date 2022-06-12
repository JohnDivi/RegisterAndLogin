
test-database: tests/database-test.cpp src/database.cpp src/database.h
	g++ -o tests/test-program-database.exe tests/database-test.cpp src/database.cpp src/database.h
