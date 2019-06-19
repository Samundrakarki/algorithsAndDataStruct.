#include <iostream>
#include <list>
#include <iterator>
#include "BST_to_SLL.h"
#include "Linked_list.h"

using namespace std;

int main(){
    LinkedList ll;
    BST bst;
    ll.add(5);
    ll.add(7);
    ll.add(3);

    ll.SLL_to_BST(bst);    
    
    cout << "Linked list is: " << endl;
    ll.print();
    cout << "Binary search tree is: " << endl;
    bst.print();
    cout << endl;
    return 0;
}