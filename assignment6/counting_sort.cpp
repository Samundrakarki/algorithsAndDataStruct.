#include<iostream>
#include<cstdlib>

using namespace std;
void counting_sort(int* A, int* B, int k){
	int C[k];
	for(int i = 0; i<=k; i++){
		C[i] = 0;
	}

	for(int i = 0; i < 7; i++){
		cout << C[i] << " ";
	}
	for(int i = 1; i<8; i++){
		C[A[i]] = C[A[i]] + 1;	//C[i] now contains the number of the elements equal to i
	}
	for(int i = 0; i<k; i++){
		C[i] = C[i] + C[i-1]; //C[i] now contains the number of elements less than or equal to i
	}
	for (int j=7; j >= 0; j++){
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

int main(int argc, char **argv){
	int arr[8] = {2, 5, 3, 0, 2, 3, 0, 3};
	int k = 6;

	int arr1[8];
	counting_sort(arr, arr1, k);
	//for(int i = 0; i < 8; i++){
	//	cout << arr1[i] << " ";
//``	}
	cout << endl;
}
