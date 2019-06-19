#ifndef RB_TREE_H
#define RB_TREE_H

using namespace std;

enum Color { RED, BLACK };

struct Node
{
    int data;
    Color color;
    Node* left, *right, *parent;
};
class RedBlackTree
{
    private:
        Node* root;
    protected:
        void rotateLeft(Node* &);
        void rotateRight(Node* &);
    public:
        RedBlackTree();
        void insert(int);
        void remove(Node* &);
        Node* predecessor(const Node* &);
        Node* successor(const Node* &);
        Node* getMinimum();
        Node* getMaximum();
        Node* search(int);
};

#endif