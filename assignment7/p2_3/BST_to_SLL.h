#ifndef BST_TO_SLL_H
#define BST_TO_SLL_H

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
        void print(Node *b_data);
    public:
        BST();
        void insert(int data);
        void print();
};

#endif