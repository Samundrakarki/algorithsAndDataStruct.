#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "BST_to_SLL.h"

using namespace std;

class Node1{
public:
    Node1* next;
    int data;
};

class LinkedList{
public:
    int length;
    Node1* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void SLL_to_BST(BST&);
    void print();
};
#endif