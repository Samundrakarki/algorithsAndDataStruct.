output: testSLL.o Linked_list.o BST_to_SLL.o
	g++ testSLL.o Linked_list.o BST_to_SLL.o

testSLL.o: testSLL.cpp
	g++ -c testSLL.cpp
	
Linked_list.o: Linked_list.cpp Linked_list.h
	g++ -c Linked_list.cpp

BST_to_SLL.o: BST_to_SLL.cpp BST_to_SLL.h
	g++ -c BST_to_SLL.cpp

clean:
	rm *.o output