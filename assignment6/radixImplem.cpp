#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <iterator>

using namespace std;

void print(int arr[], int n);
int findMax(int arr[], int n);
int * radix_hollerith(int array[], int bucket[], int i, int n);


int main() {
    int n = 17;
    int arr[n] =  {6, 7, 4, 333, 22, 23, 21, 444, 123, 1233, 1123, 1, 0, 12, 440, 11, 1233};
    int *sorted_arr;
    int bucket[10] = {0};
    int digit;
    int max = findMax(arr, n);
    string s = to_string(max);
    digit = s.length();
    
    cout << "Unsorted version of the array: " << endl;
    print(arr, n);
    cout << endl;
    cout << "Sorted version of the array: " << endl;
    
    
    sorted_arr = radix_hollerith(arr, digit, n);
    // print(arr, n);
    return 0;
}
int findMax(int arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int* radix_hollerith(int array[] ,int i, int n){
    int size = n;
    
    if(bucket_length <= 1)
        return array;
    if(i >= size)
        return array;
    for(int j = 0; j<n; j++){
        int index = (int) ((array[j])/(pow(10, i-1)))%10;
        bucket[index]= array[j];
    }
    // for(int j = 0; j < bucket_length; j++){

    // }   
    return NULL;
}


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
