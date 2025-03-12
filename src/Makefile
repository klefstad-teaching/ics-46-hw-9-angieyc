CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

all: ladder dijkstras

ladder: ladder.o ladder_main.o
	$(CXX) $(CXXFLAGS) -o ladder ladder.o ladder_main.o

ladder.o: ladder.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder.cpp -o ladder.o

ladder_main.o: ladder_main.cpp ladder.h
	$(CXX) $(CXXFLAGS) -c ladder_main.cpp -o ladder_main.o

dijkstras: dijkstras.o dijkstras_main.o
	$(CXX) $(CXXFLAGS) -o dijkstras dijkstras.o dijkstras_main.o

dijkstras.o: dijkstras.cpp dijkstras.h
	$(CXX) $(CXXFLAGS) -c dijkstras.cpp -o dijkstras.o

dijkstras_main.o: dijkstras_main.cpp dijkstras.h
	$(CXX) $(CXXFLAGS) -c dijkstras_main.cpp -o dijkstras_main.o

clean:
	/bin/rm ladder dijkstras *.o