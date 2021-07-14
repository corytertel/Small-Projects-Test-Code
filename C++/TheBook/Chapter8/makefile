OBJS = main.o fibonacci_range.o fibonacci_iterator.o prime_number_range.o prime_number_iterator.o
CXX = g++
CPPFLAGS = -g -c -Wall -std=c++20
LDFLAGS = -g -Wall -std=c++20
EXE = main

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXE)

prime_number_iterator.o: prime_number_iterator.h prime_number_iterator.cpp
	$(CXX) $(CPPFLAGS) prime_number_iterator.cpp

prime_number_range.o: prime_number_range.h prime_number_range.cpp prime_number_iterator.h
	$(CXX) $(CPPFLAGS) prime_number_range.cpp

fibonacci_iterator.o: fibonacci_iterator.h fibonacci_iterator.cpp
	$(CXX) $(CPPFLAGS) fibonacci_iterator.cpp

fibonacci_range.o: fibonacci_range.h fibonacci_range.cpp fibonacci_iterator.h
	$(CXX) $(CPPFLAGS) fibonacci_range.cpp

main.o: main.cpp fibonacci_range.h prime_number_range.h
	$(CXX) $(CPPFLAGS) main.cpp

clean:
	rm *.o $(EXE) -v
