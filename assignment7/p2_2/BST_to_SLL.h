#ifndef BST_TO_SLL_H
#define BST_TO_SLL_H
#include "Linked_list.h"
using namespace std;
struct Node{
        int data;
        Node* right;
        Node* left;
};

class BST{
    private:
        Node* root;
        void insert(int data, Node *leaf);
        void bst_to_SLL(LinkedList&, Node*);
        void print(Node *b_data);
    public:
        BST();
        void insert(int data);
        void print();
        void bst_to_SLL(LinkedList&);
};

#endif