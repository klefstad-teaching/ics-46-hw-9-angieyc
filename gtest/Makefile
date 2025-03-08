CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic -I ../src/

tests: ladder.o student_gtests.cpp
	g++ $(CXXFLAGS) student_gtests.cpp -o tests ladder.o -lgtest -lgtest_main -pthread
ladder.o: ../src/ladder.cpp ../src/ladder.h 
	g++ $(CXXFLAGS) -c ../src/ladder.cpp -o ladder.o
clean:
	/bin/rm tests *.o