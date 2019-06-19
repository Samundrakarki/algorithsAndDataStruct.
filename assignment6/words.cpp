#include <iostream>
#include <string>

using namespace std;

int ASCII(string words, int i){
    if(int(words.length()) > i)
        return (words[i]);
    else 
        return 0;
}
int getMaxLetters(string words[], int n){
    int max = words[0].length();
    for(int i = 1; i < n; i++){    

        if((int(words[i].length()) > max)){
            max = words[i].length();
        }
    }
    return max;
}
int getMaxASCII(string words[], int n, int index){
    int max = words[0][index];
    for(int i = 0; i < n; i++){
         if((words[i][index] > max)){
            max = words[i][index];
        }
    }
    return max;
}

void radix(string words[],string sorted_words[] ,int index, int n){

    int k = getMaxASCII(words, n, index);
    int C[k], temp = 0;
    for(int i = 0; i<= k; i++) {
        C[i] = 0;
    }
    
    for(int i = 0; i < n ; i++){
        temp = ASCII(words[i], index);
        C[temp] = C[temp] + 1; 
    }

    for(int i = 1; i <= k; i++){
        C[i] += C[i-1];
    }  

    for(int i = (n-1); i >= 0; i--){
        int j =ASCII(words[i], index);
        sorted_words[C[j]-1] = words[i];
        C[j] -= 1;
    }
}

void wordsort(string words[],string sorted_words[], int n){
    int k = getMaxLetters(words, n) - 1;
    for(int i = k; i >=0; i--){
       radix(words, sorted_words, i ,n);
    }
}


int main(){
    int n = 10;
    string words[n] = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
    string *sorted_words;
    sorted_words = new string[n];

    for(int i = 0; i < n; i++){
        sorted_words[i] = "";
    }
    for(int i = 0; i < n; i++){
        cout << words[i] << " ";
    }
    cout << endl;
    wordsort(words,sorted_words, n);
    for(int i = 0; i < n; i++){
        cout << sorted_words[i] << " ";
    }

}