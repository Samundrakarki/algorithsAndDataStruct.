#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


long int fib_naive_recurrsion(unsigned long int N){
    if (N <=1 ){
        return N;
    }
    return fib_naive_recurrsion(N - 1) + fib_naive_recurrsion(N - 2);
}



long int fib_bottom_up(unsigned long int n){
    unsigned long long int fib[n+1];
    
    //base cases
    fib[0] = 0; 
    fib[1] = 1;

    for(unsigned long long int i = 2; i <= n; i++){
        fib[i]= fib[i -1] + fib[i -2];
    }
    return fib[n];
}

long int fib_closed_Form(unsigned long int n){
    long double first, second, third, fourth;
    first = 1 / pow(5, 0.5);
    second = (1 + pow(5, 0.5)) / 2;
    third = (1 - pow(5, 0.5)) /2;
    fourth = first * (pow(second, n) - pow(third, n));

    return fourth;
}

void multiply_matrix(unsigned long int first_matrix[2][2], unsigned long int second_matrix[2][2]){

 unsigned  long int temp_matrix[2][2] = {{0, 0}, {0, 0}};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                temp_matrix[i][j] += first_matrix[i][k]*second_matrix[k][j];
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            first_matrix[i][j] = temp_matrix[i][j];
        }
    }
}


void divide_and_conquer(unsigned long int first_marix[2][2],unsigned  long  int n){
    if(n == 0 || n == 1){
       return;
   }

    divide_and_conquer(first_marix, n/2);
    multiply_matrix(first_marix, first_marix);

    unsigned long int second_matrix[2][2] = {{1, 1}, {1, 0}};
    if(n%2){
       multiply_matrix(first_marix, second_matrix);
    }
}

unsigned long int  fib_matrix(unsigned long int n){
    if(n == 1 || n == 2){
        return 1;
    }

   unsigned  long int fib_matrix[2][2] = {{1, 1}, {1, 0}};
    divide_and_conquer(fib_matrix, n);

    return fib_matrix[0][1];
}

int main(){

    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL){
        exit(1);
    }

    unsigned long int n = 50;
    double naive_time, bottom_up_time, closed_form_time, matrix_time;
    clock_t start, end;
    for (unsigned long int i = 0; i < n; i++){

        start = clock();
        fib_naive_recurrsion(i);
        end = clock();printf("%f ", naive_time);
        naive_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        

        start = clock();
        fib_bottom_up(i);
        end = clock();
        bottom_up_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        


        start = clock();
        fib_closed_Form(i);
        end = clock();
        closed_form_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        

        start = clock();
        fib_matrix(i);
        end = clock();
        matrix_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        fprintf(fp, "%ld    %.10f    %.10f    %.10f    %.10f\n",i ,naive_time, bottom_up_time, closed_form_time, matrix_time);

    }
    fclose(fp);
    return 0;
}