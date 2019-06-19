#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack(){
    size = -1;
    current_size = 0;
}

template <class T>
Stack<T>::Stack(int new_size){
    size = new_size;
    current_size = 0;
}

template <class T>
void Stack<T>::push(T data){
    Node<T>* newNode = new Node<T>;
    if(size == current_size){
        cout << "Overflow!" << endl;
        exit(1);
    }else if(current_size == 0){
        newNode->data = data;
        newNode->next = NULL;
        top = newNode;
        current_size++;
    }else{
        newNode->data = data;
        newNode->next = this->top;
        this->top = newNode;
        current_size++;
    }
}

template <class T>
T Stack<T>::pop(){
    Node<T>* newNode = new Node<T>;
    if(current_size == 0){
        cout << "UnderFlow"<< endl;
        exit(1);
    }else{
        newNode = this->top;
        this->top = (top->next);
        delete newNode;
        this->current_size--;
        return newNode->data;
    }
}
template <class T>
bool Stack<T>::isEmpty(){
    if(current_size == 0){
        return true;
    }else{
        return false;
    }
}

template <class T>
void Stack<T>::print(){
    Node<T>* newNode = new Node<T>;
    newNode = this->top;

    while(newNode != NULL){    
        cout << newNode->data << " ";
        newNode = (newNode->next);
    }
    cout << endl;
}

//any type that needs to be used can be added here
template class Stack<int>;
template class Stack<char>;