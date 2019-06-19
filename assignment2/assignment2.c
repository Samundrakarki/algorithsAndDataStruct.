#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void Merge_Sort(int arr[], int length);
void Insertion_Sort(int *arr, int length);
void Merge(int *arr, int *sub_array1, int *sub_array2, int length);


int main(){
    int array[8] =  {0, 15, 25, 10, 15, 20, 7, 2};
    Merge_Sort(array, 8);

    for(int i = 0; i < 8; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void Merge_Sort(int *arr, int length){
    int mid_point = 0;
    int *sub_array1, *sub_array2;
    mid_point = length / 2;

    
    if(length < 1){
        return;
    }
    else{
        sub_array1 = (int*) malloc(sizeof(int) * mid_point);
        sub_array2 = (int*) malloc(sizeof(int) * (length - mid_point));
        

        for(int i = 0; i < mid_point; i++){
            sub_array1[i] = arr[i];
        }
        
        for(int i = mid_point; i < length; i++){
            sub_array2[i - mid_point] = arr[i];
        }
        Merge_Sort(sub_array1, mid_point);
	    Merge_Sort(sub_array2, length - mid_point);
	    Merge(arr, sub_array1, sub_array2, length);
    }
        
    free(sub_array1);
    free(sub_array2);
}



void Merge(int *arr, int *sub_array1, int *sub_array2, int length){
    int m1, m2;
    int i = 0, j = 0, k = 0;
    
    m1 = length / 2;
    m2 = length - m1;

    while(i < m1 && j < m2){
        if(sub_array1[i] < sub_array2[j]){
            arr[k] = sub_array1[i];
            i++;
        }else {
            arr[k] = sub_array2[j];
            j++;
        }
        k++;
    }
    while(i < m1){
        arr[k] = sub_array1[i];
        i++;
        k++;
    }
    while(j < m2){
        arr[k] = sub_array2[j];
        j++;
        k++;
    }
}
