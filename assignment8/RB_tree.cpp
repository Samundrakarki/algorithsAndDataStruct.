#include <iostream>
#include "RB_tree.h"

void RedBlackTree::rotateLeft(Node* &x){
    if(x->right == nullptr){
        return;
    }else{
        Node* y = x->right;
        if(y->left != nullptr){
            x->right = y->left;
            y->left->parent = x;
        }else x->right = NULL;
        if(x->parent != nullptr){
            y->parent = x->parent;
        }
        if (x->parent == nullptr){
            root = y;
        }else {
            if(x = x->parent->left){}
            
        }
    }
}