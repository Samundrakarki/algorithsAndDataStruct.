#include <iostream>
#include <list>
#include <iterator>
#include "BST_to_SLL.h"
#include "Linked_list.h"

using namespace std;

int main(){
    LinkedList ll;
    BST bst;
    bst.insert(5);
    bst.insert(7);
    bst.insert(4);
    bst.insert(19);
    bst.insert(25);
    bst.insert(11);
    bst.insert(7);
    bst.insert(8);    
    
	cout << "Binary search tree : " << endl;
    bst.print();
	cout << endl;
	//conversion binary search tree to sorted linked list
    bst.bst_to_SLL(ll);
	
	cout << "Linked list: " << endl;
    ll.print();
    return 0;
}
