#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void heapify(int arr[], int n, int i);
void heap_sort(int arr[], int n);

void Build_max_heap(int arr[], int n);
int* random_sequence(int n);

void heap_variant(int a[],int i,int size);
void heap_sort_variant(int arr[], int n);

void print_sorted(int arr[], int n);

#endif
