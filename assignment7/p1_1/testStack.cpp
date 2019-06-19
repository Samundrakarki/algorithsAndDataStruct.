#include <iostream>
#include <ctime>
#include "stack.h"

int main(int argc, char** argv){
    Stack<int>s;
    Stack<char> obj(5);
    int j = 0;
    if(s.isEmpty()){
        cout << "This stack is empty" << endl;
    }
    while(j < 5){
        obj.push('a'+j);
        j++;
    }
    // uncomment this to know if the list will produce overflow or not
    // obj.push('f');
    obj.print();
    
    int start_s = clock();
    for(int i = 0; i < 10000000; i++){
        s.push(i);
    }
    int stop_s = clock();

    int start_s1 = clock();
    for(int i = 0; i < 10000000; i++){
        s.pop();
    }
    int stop_s1 = clock();
     if(s.isEmpty()){
        cout << "This stack is empty" << endl;
    }
    cout << "Time taken for 100000 pushes is: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    cout << "Time taken for 100000 pops is: " << (stop_s1-start_s1)/double(CLOCKS_PER_SEC)*1000 << endl;
    
}