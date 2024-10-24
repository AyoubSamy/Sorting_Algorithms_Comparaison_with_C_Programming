/*ce fichier sert a assurer la modularite du projet ainsi d'eviter les erreurs de compilation et la redondance */

#ifndef SORTING_H
#define SORTING_H

/*declaration de tout les fonctions utiliser dans le fichier "sorting.c" qui implimente les methodes de tri */
void bubble_sort(int arr[], int length, FILE *ptrfile);

void insertion_sort(int arr[], int length, FILE *ptrfile);

void merge_sort(int arr[], int length, FILE *ptrfile);
void merge_sort_recursion(int arr[], int left_index, int right_index);
void merge_sorted_arrays(int arr[], int left_index, int middle_index, int right_index);

void swap(int *x, int *y);

void selectionSort(int T[], int n , FILE *ptrfile);

void Quicksort(int array[],int lenght,FILE *ptrfile);
void QuickSort_Recursion(int array[],int low,int high);
int  partition(int array[],int low,int high);

#endif