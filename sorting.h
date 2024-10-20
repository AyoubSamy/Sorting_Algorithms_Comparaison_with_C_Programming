#ifndef SORTING_H
#define SORTING_H


void bubble_sort(int arr[], int length, FILE *ptrfile);

void insertion_sort(int arr[], int length, FILE *ptrfile);

void merge_sort(int arr[], int length, FILE *ptrfile);

void merge_sort_recursion(int arr[], int left_index, int right_index);

void merge_sorted_arrays(int arr[], int left_index, int middle_index, int right_index);

void quick_sort(int arr[], int length, FILE *ptrfile);

void swap(int *x, int *y);



#endif