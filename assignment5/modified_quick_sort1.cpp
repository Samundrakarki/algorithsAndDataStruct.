#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void partition_first(int *arr, int p, int q, int *pos0, int *pos1);
void modified_quick_sort(int *arr,int p, int q);
int* random_sequence(int n);

int main(){
	int n = 1000;
	int *arr = random_sequence(n);

	modified_quick_sort(arr, 0, n-1);

	for(int i =0 ; i< n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void modified_quick_sort(int *arr ,int p, int r){
	if(p < r){
        int pos0, pos1;
		partition_first(arr, p, r, &pos0, &pos1);
		modified_quick_sort(arr, p, pos0-1);
		modified_quick_sort(arr, pos0+1, pos1-1);
		modified_quick_sort(arr,pos1+1, r);
	}
	
}


void partition_first(int *arr, int p, int q, int* pos0, int* pos1){ 

	//swapping the scond and first element if second is smaller than first
	if(arr[p] > arr[p+1]){
		swap(arr[p], arr[p+1]);
	}

    //swapping second and last element 
    swap(arr[p+1], arr[q]);

    //setting pivot1 and pivot2 as first and last element
    int pivot1 = arr[p];
    int pivot2 = arr[q];

    //setting psoition 
    int pivot_pos1 = p + 1;
    int pivot_pos2 = q -1;

    //seeting for while loop
    int checker = p + 1;

    while((checker <= pivot_pos2)){
        if(arr[checker] < pivot1){
            swap(arr[checker], arr[pivot_pos1]);
            checker++;
            pivot_pos1 ++;        
        }else if(arr[checker] > pivot2){
            swap(arr[checker], arr[pivot_pos2]);
            pivot_pos2--;
        }else{
        checker++;
        }
    }
    pivot_pos1--;
    pivot_pos2++;
    swap(arr[pivot_pos1], arr[p]);
    swap(arr[pivot_pos2], arr[q]);

    *pos0= pivot_pos1 ;
    *pos1 = pivot_pos2;
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