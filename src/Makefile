CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all: ladder

ladder: ladder.o ladder_main.o
	$(CXX) $(CXXFLAGS) -o ladder ladder.o ladder_main.o

ladder.o: ladder.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder.cpp -o ladder.o

ladder_main.o: ladder_main.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder_main.cpp -o ladder_main.o

clean:
	/bin/rm ladder *.o