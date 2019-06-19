#include <iostream> 
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "heap_sort.h" 

using namespace std;

void heapify(int arr[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; // left child
    int r = 2*i + 2; // right child 
  
    // left child is larger than root then largest is left child 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // right child is larger than largest then largest is right child 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If in this condiotn largest will not equal to i then swap and heapify with the index largest
    if (largest != i) 
    { 
        std::swap(arr[i], arr[largest]); 
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

//this function is used to build the max-heap
void Build_max_heap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, n, i); 
    }
}

void heap_sort(int arr[], int n) 
{  
    Build_max_heap(arr, n);
  
    for (int i=n-1; i>=0; i--) 
    {  
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0); 
    }
} 

void heap_sort_variant(int arr[], int n) 
{  
    Build_max_heap(arr, n);
  
    for (int i=n-1; i>=0; i--) 
    {  
        swap(arr[0], arr[i]);  
        heap_variant(arr,0 ,i); 
    }
}

void print_sorted(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    } 
        cout << "\n"; 
}


int* random_sequence(int n){
    int * random_case;
    random_case = new int[n];
    srand ( static_cast < unsigned int >( time (0) ) );

    for(int i = 0; i<n; i++){  
        int random_number = rand() % 1000 + 1;
        random_case[i] = random_number;
    }
    return random_case;
}


  


