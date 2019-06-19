#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstdlib>

using namespace std;

class Queue{
    private:
        stack<int> input_stack;
        stack<int> output_stack;
    public:
        Queue();
        ~Queue();
        void Enqueue(int data);
        int Dequeue();
};

Queue::Queue(){}
Queue::~Queue(){
    while(!input_stack.empty()){
        input_stack.pop();
    }
    cout << endl;
}

//Enqueue takes more time than dequeue.
//It takes O(1) in best case: Only one element
//It takes O(n) in average and worst case: Elments > 1
void Queue::Enqueue(int data){

    //making the stack emppty and storing the elemnt in the first place so that oldset remain on the top
    while(!input_stack.empty()){
        output_stack.push(input_stack.top());
        input_stack.pop();
    }

    //pushing element in the first place
    input_stack.push(data);

    //pushing all th other element form output_stack
    while(!output_stack.empty()){
        input_stack.push(output_stack.top());
        output_stack.pop();
    }

}
//It is more efficient.
//It take O(1) in worst case.
int Queue::Dequeue(){
    if(input_stack.empty()){
        exit(1);
    }
    
    //for returing the topmost element
    int elem = input_stack.top();

    //popping the last element
    input_stack.pop();
    return elem;
}



int main(int argc, char **argv){
    Queue q;
    int i = 0;

    //enquing the element
    while(i<10){
        q.Enqueue(i);
        i++;
    }

    //dequeing the element
    cout << q.Dequeue();
    return 0;
}

