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
    int i = 1;
    while(head != NULL){
        cout <<head->data << " ";
        head = head->next;
        i++;
    }
    cout << endl;
}

void LinkedList::SLL_to_BST(BST& tobst){
    Node1* head = this->head;
    if(head == NULL){
        return;
    }else{
        while(head != NULL){
            tobst.insert(head->data);
            head = head->next;
        }
    }
}