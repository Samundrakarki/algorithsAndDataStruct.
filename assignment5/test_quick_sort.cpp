
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "quick_sort.h"
using namespace std;

int main(){
	int n = 100000;
	int fixed_size = 1000;
	double time_taken_Lomoto, time_taken_Hoare, time_taken_med;
	double total_time_Lomoto = 0, total_time_Hoare = 0, total_time_med = 0;
	clock_t start, end;
	for(int i = 0; i < n; i++){
		int *arr = random_sequence(fixed_size);
		int *arr1, *arr2;

		arr1 = new int[fixed_size];
		arr2 = new int[fixed_size];
		
		for(int i = 0; i < fixed_size; i++){
			arr1[i] = arr[i];
			arr2[i] = arr[i];
		}

		start = clock();
		med_quick_sort(arr, 0, fixed_size-1);
		end = clock();
		
		time_taken_med	= ((double) end -start)/CLOCKS_PER_SEC;
		total_time_med += time_taken_med;


		start= clock();
		Hoare_quick_sort(arr1, 0, fixed_size -1);
		end = clock();

		time_taken_Hoare = ((double) end -start)/CLOCKS_PER_SEC;
		total_time_Hoare += time_taken_Hoare;		
		
		start = clock();		
		Lomoto_quick_sort(arr2, 0,fixed_size -1);
		end = clock();
		
		time_taken_Lomoto = ((double) end -start)/CLOCKS_PER_SEC;
		total_time_Lomoto += time_taken_Lomoto;

		delete [] arr1;
		delete [] arr2;
	}
	cout << "Average of time taken by Lomoto is:" << (total_time_Lomoto/n) << endl;
	cout << "Average of time taken by Hoare is:" << (total_time_Hoare/n) << endl;
	cout << "Average of time taken by med is:" << (total_time_med/n) << endl;
}
