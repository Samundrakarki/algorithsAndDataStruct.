/* 
*Stack implementation backed up by linked list.
*Analyze the run time of eah operation
*/
#ifndef STACK_H
#define STACK_H

using namespace std;

template <class T>
class Node{
    public:
        Node* next;
        T data;
};

template <class T>
class Stack{
    private:
        Node<T>* top;
        int size;
        int current_size;
    public:
        Stack();
        Stack(int );
        void push(T);
        T pop();
        bool isEmpty();
        void print();
};
#endif
