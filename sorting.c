#include <stdio.h>
#include <stdbool.h>
#include "sorting.h"
#include<time.h>
#include<stdlib.h>

clock_t begin;
double executionTime;

void bubble_sort(int arr[], int length, FILE *ptrfile){
    begin = clock();
    bool swapped = false;
    int i = 0;

    do
    {
        swapped = false;
        for (int j = 0; j < (length - 1 - i); j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        i++;

    } while (swapped);
    executionTime = ((double)(clock() - begin)) / CLOCKS_PER_SEC * 1000;
    fprintf(ptrfile, "%d\t%lf\n", length, executionTime);
}


void insertion_sort(int arr[], int length, FILE *ptrfile){
    begin = clock();
    for (int i = 1; i < length; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] =  arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    executionTime = ((double)(clock() - begin)) / CLOCKS_PER_SEC * 1000;
    fprintf(ptrfile,"%d\t%lf\n", length, executionTime);
}

void merge_sort(int arr[], int length, FILE *ptrfile){
    begin = clock();
    merge_sort_recursion(arr, 0, length - 1);
    executionTime = ((double)(clock() - begin)) / CLOCKS_PER_SEC * 1000;
    fprintf(ptrfile,"%d\t%lf\n", length, executionTime);
}


void merge_sort_recursion(int arr[], int left_index, int right_index){

    if (left_index < right_index)
    {
        int middle_index = left_index + (right_index - left_index) / 2;

        merge_sort_recursion(arr, left_index, middle_index);
        merge_sort_recursion(arr, middle_index + 1, right_index);

        merge_sorted_arrays(arr, left_index, middle_index, right_index);
    }
}


void merge_sorted_arrays(int arr[], int left_index, int middle_index, int right_index){
    int left_length = middle_index - left_index + 1;
    int right_length = right_index - middle_index;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++) temp_left[i] = arr[left_index  + i];
    for (int i = 0; i < right_length; i++) temp_right[i] = arr[middle_index + 1 + i];
    
    for(i = 0, j = 0, k = left_index; k <= right_index; k++){
        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j])
            )
        {
            arr[k] = temp_left[i];
            i++;
        }else{
            arr[k] = temp_right[j];
            j++;
        }
        
    }
}

void quick_sort(int arr[], int length, FILE *ptrfile){

}

void swap(int *x, int *y){
    
}
