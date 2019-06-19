#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "heap_sort.h"


using namespace std;

int main() 
{ 
    int n = 100000;
    ofstream my_file;
    int *arr, *arr1;
    double time_taken, time_taken_variant;

    my_file.open("data.txt");
    clock_t start, end;

    for (int i = 500; i <= n; i+=500){
        arr = random_sequence(i);
        arr1 = new int[i];
        for(int j = 0; j < i; j++){
            arr1[j] = arr[j]; 
        }

        start = clock();
        heap_sort(arr, i);
        end = clock();

        time_taken = ((double) end - start) / CLOCKS_PER_SEC;
        my_file << time_taken;
        my_file << " ";

        start = clock();
        heap_sort_variant(arr1, i);
        end = clock();

        time_taken_variant = ((double) end - start) / CLOCKS_PER_SEC;
        my_file << time_taken_variant;
        my_file << endl;
       
        delete [] arr;
        delete[] arr1;    
        }

} 