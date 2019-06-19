#include <iostream>
#include "BST_to_SLL.h"
#include "Linked_list.h"

using namespace std;

BST::BST(){
    this->root = nullptr;
}

void BST::insert(int x){
   if(this->root != nullptr){
       insert(x, this->root);
   }else{
       root = new Node;
       root->data = x;
       root->left = nullptr;
       root->right = nullptr;
   }
}

void BST::insert(int data, Node* leaf){
    if(data < leaf->data){
        if(leaf->left != nullptr){
            insert(data, leaf->left);
        }else{
            leaf->left = new Node;
            leaf->left->data = data;
            leaf->left->left =  nullptr;
            leaf->left->right = nullptr;
        }
    }else if(data >= leaf->data){
        if(leaf->right != nullptr){
            insert(data, leaf->right);
        }else{
            leaf->right = new Node;
            leaf->right->data = data;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}
void BST::print(){
    if(this->root == nullptr)
        return;
    else{
        print(this->root);
    }
}

void BST::print(Node* x){
     if (x != nullptr){
         print(x->left);
        cout << x->data << " ";
         print(x->right);
    }
}


void BST::bst_to_SLL(LinkedList& mylist){
    if(this->root == NULL){
        return ;
    }
    else{
        bst_to_SLL(mylist, this->root);
    }
}

void BST::bst_to_SLL(LinkedList& mylist, Node *leaf){
    if(leaf->right != NULL){
        bst_to_SLL(mylist, leaf->right);
    }
    mylist.add(leaf->data);

    if(leaf->left != NULL){
        bst_to_SLL(mylist, leaf->left);
    }
}

