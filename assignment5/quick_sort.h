#include <iostream>
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

int med_partition(int *arr, int p, int q);
int Lomoto_partition(int *arr, int p, int q);
int Hoare_partition(int *arr, int s, int l);
int median_pivot(int *arr, int p , int r);

 
void Lomoto_quick_sort(int *arr, int p, int r);
void Hoare_quick_sort(int *arr, int p, int r);
void med_quick_sort(int *arr, int p, int r);

int* random_sequence(int n);

#endif