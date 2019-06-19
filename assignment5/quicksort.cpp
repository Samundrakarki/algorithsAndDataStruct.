#include <iostream>
#include <cstdlib>
#include <ctime>

#include "quick_sort.h"
using namespace std;


void med_quick_sort(int *arr, int p, int r){
    if(p < r){
        int q = med_partition(arr, p, r);
        med_quick_sort(arr, p, q -1);
		med_quick_sort(arr, q+1, r);
    }
}

void Lomoto_quick_sort(int *arr, int p, int r){
    if(p < r){
        int q = Lomoto_partition(arr, p, r);
        Lomoto_quick_sort(arr, p, q-1);
		Lomoto_quick_sort(arr, q+1, r);
    }
}


void Hoare_quick_sort(int *arr, int p, int r){
    if(p < r){
        int q = Hoare_partition(arr, p, r);
        Hoare_quick_sort(arr, p, q);
		Hoare_quick_sort(arr, q+1, r);
    }
}


int Lomoto_partition(int *arr, int p, int q){
    int x = arr[p];
    int i = p;
    for(int j = p+1; j <= q; j++){
    	if(arr[j] <= x ){
	    i = i + 1;
	    swap(arr[j], arr[i]);
		}
    }
    swap(arr[p], arr[i]);
    return i;
}

int Hoare_partition(int *arr, int s, int l){
    int x = arr[s];
    int i = s - 1;
    int j = l + 1;

    while(true)
    {
        do
		{
		    i++;
		} while (arr[i] < x);

		do
		{
			j--;
		} while(arr[j] > x);

		if(i >= j){
			return j;
		}

		swap(arr[i], arr[j]);
    }
}

int med_partition(int *arr, int p, int r){
    int x = median_pivot(arr, p, r);
    int i = p;
    for(int j = p+1; j <= r; j++){
    	if(arr[j] <= x ){
	    i = i + 1;
	    swap(arr[j], arr[i]);
		}
    }
    swap(arr[p], arr[i]);
    return i;
}

int median_pivot(int *arr, int p, int r){
    int x = arr[p];
    int y = arr[r];
    int z = arr[r/2];

    if((y > x && y < z) || (y > x && y < z)) x = y;
    else if((z > x && z < y) || (z > y && z < x)) x = z;
    return x;
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
