#include <iostream>
#include "Linked_list.h"

using namespace std;

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
}

void LinkedList::add(int data){
    Node1* node = new Node1();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node1* head = this->head;
    while(head){
        std::cout<< head->data << " ";
        head = head->next;
    }
	cout << endl;
}
