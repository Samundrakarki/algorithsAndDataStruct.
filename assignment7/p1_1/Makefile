output: stack.o testStack.o
	g++ stack.o testStack.o

stack.o: stack.cpp stack.h
	g++ -c stack.cpp
	
testStack.o: testStack.cpp
	g++ -c testStack.cpp

clean:
	rm *.o output
