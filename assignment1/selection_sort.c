#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int* best_case_scenerio( int s);
int* worst_case_scenerio( int s);

//random _ sequence is  a function that generates a random number sequence. 
int* random_sequence(int n);

//selection sort is a function which sorts the arrays provided to them
void selection_sort(int *arr, int n);

//this array is defined in global scope and

int main(){
    int n=20000;
    double worst_total_time;
    double best_total_time;
    double random_total_time;
	clock_t start, end;

    FILE *fs;
    fs = fopen("data.dat", "w+");
	if(fs == NULL){
        exit(1);
    }

    for (int s=7000 ; s <= n ; s+=1000){

        int* worst_case_arr = worst_case_scenerio(s);
        start = clock();    
        selection_sort(worst_case_arr, s);
        end = clock();
        free(worst_case_arr);
        worst_total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf(" %f \n", worst_total_time);    
        
        
        int* best_case_arr = best_case_scenerio(s);
        start = clock();
        selection_sort(best_case_arr, s);
        end = clock();
        free(best_case_arr);
        best_total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf(" %f \n", best_total_time);    
    
        int* random_case_arr = random_sequence(s);
        start = clock();
        selection_sort(random_case_arr, s);
        end = clock();
        free(random_case_arr);
        random_total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf(" %f \n", random_total_time);

        fprintf(fs, "%d %lf %lf %lf\n", s, worst_total_time, random_total_time, best_total_time);
    }
    
    fclose(fs);

 	return 0;
}

int* best_case_scenerio( int s){
    int *best_case;
    best_case = (int*)malloc(s * sizeof(int));
    best_case[0] = rand();
    for(int i = 1; i < s; i++){
        best_case[i] = i + best_case[i-1];
    }
    return best_case;
}

int* worst_case_scenerio( int s){
    int *worst_case;
    worst_case = (int*)malloc(s * sizeof(int));
    worst_case[0] = rand();
    for(int i = 1; i < s; i++){
        worst_case[i] = worst_case[i-1] - i;
    }
    return worst_case;
}

void selection_sort(int *arr, int n){
    for(int i = 0; i < n -1; i++){
        int iMin = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[iMin]){
                iMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[iMin];
        arr[iMin] = temp;
    }
}

int* random_sequence(int n){
    int * random_case;
    random_case = (int*) malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i<n; i++){  
        int random_number = rand() % 100 + 1;
        random_case[i] = random_number;
    }
    return random_case;
}