.PHONY: clean all test
CXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic -Werror -Iinclude

all: bin main

bin:
	mkdir -p bin

main: bin/main.o bin/BoardView.o bin/Board.o
	$(CXX) $(CXXFLAGS) bin/main.o bin/BoardView.o bin/Board.o -o main

bin/main.o: src/main.cpp include/*.h 
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o bin/main.o

bin/BoardView.o: src/BoardView.cpp include/*.h
	$(CXX) $(CXXFLAGS) -c src/BoardView.cpp -o bin/BoardView.o

bin/Board.o: src/Board.cpp include/*.h 
	$(CXX) $(CXXFLAGS) -c src/Board.cpp -o bin/Board.o

board_test: bin bin/test.o bin/Test.o bin/BoardTest.o bin/Board.o include/*.h 
	$(CXX) bin/test.o bin/Test.o bin/BoardTest.o bin/Board.o -o board_test
	
bin/test.o: test/test.cpp include/*.h 
	$(CXX) $(CXXFLAGS) -c test/test.cpp -o bin/test.o
	
bin/Test.o: test/Test.cpp include/*.h 
	$(CXX) $(CXXFLAGS) -c test/Test.cpp -o bin/Test.o

bin/BoardTest.o: test/BoardTest.cpp include/*.h
	$(CXX) $(CXXFLAGS) -c test/BoardTest.cpp -o bin/BoardTest.o

clean:
	rm -rf bin main board_test
