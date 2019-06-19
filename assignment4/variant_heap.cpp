#include <iostream>
#include <algorithm>
#include "heap_sort.h"

using namespace std;



void push_downwards(int *arr, int i, int size){
    int l_child, r_child;
    int new_index = i;
    l_child = (2 * i) + 1;
    r_child = (2 * i) + 2;

    if(l_child >= size){
        return;
    }else if(r_child >= size){
        swap(arr[i], arr[l_child]);
        return;
    }else{
        if (arr[l_child]>arr[r_child]){
            swap(arr[i],arr[l_child]);
            new_index=l_child;
        }else{
            swap(arr[i],arr[r_child]);
            new_index=r_child;
        }
        push_downwards(arr, new_index, size);
    }
}

void raise_element(int *arr, int i){
    if(arr[(i-1)/2] < arr[i]){
        swap(arr[(i-1)/2], arr[i]);
        raise_element(arr, (i-1)/2);
    }
}

void heap_variant(int arr[],int i,int size){
    push_downwards(arr, i, size);
    raise_element(arr, i);
}