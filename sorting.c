#include <stdio.h>
#include <stdbool.h>
#include "sorting.h"/**/
#include<time.h>/*directive pour manipuler le temp (mesurer le temp d'execution des algorithmes de tri)*/
#include<stdlib.h>

clock_t begin; /*declaration de varibale begin de type clock_t(est un type utiliser pour stocker le temp processur) */
double executionTime;

/*implimentation de tri a bulle */

void bubble_sort(int arr[], int length, FILE *ptrfile/*pointeur de type File pour manipuler un fichier */){
    begin = clock();
    bool swapped = false;
    int i = 0;

    do
    {
        swapped = false; 

        for (int j = 0; j < (length - 1 - i); j++){
            /*permuter deux element successive si le premier est superieur au suivant */
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; 
            }
        }
        i++;

    } while (swapped);/* sortir de la boucle si on est plus des paires a permuter */

    executionTime = ((double)(clock() - begin)) / CLOCKS_PER_SEC * 1000;/*calcule de temp d'execution de l'algorithme en milliseconde*/
    fprintf(ptrfile, "%d\t%lf\n", length, executionTime);/*ecriture du temp trouver avec la taille de la liste dans le fichier pointer*/
}

/*implimentation de tri par insertion  */

void insertion_sort(int arr[], int length, FILE *ptrfile){
    begin = clock();
    for (int i = 1; i < length; i++){ /*parcourire toute la liste */
        int current = arr[i]; /*recuperer l'element a inserer dans labon position */
        int j = i - 1;
        while (j >= 0 && arr[j] > current){ /*trouver la bon position */
            arr[j + 1] =  arr[j];/*icraser l'element en cours par l'element juste avant(retrier la liste avant l'element en cour)*/
            j = j - 1;
        }
        arr[j + 1] = current; /*inserer l'element en cour  dans sa bon place */
    }

    executionTime = ((double)(clock() - begin)) / CLOCKS_PER_SEC * 1000;
    fprintf(ptrfile,"%d\t%lf\n", length, executionTime);
}

/*implimentation de tri par fusion  */

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

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int T[], int n, FILE *ptrfile)
{
    begin = clock();
    int i , j;
    for(i=0; i<n-1; i++){
        int imin=i;
        for(j=i+1; j<n; j++){
            if(T[imin] >  T[j])
              imin = j;  
        }
        if(imin != i)
        swap(&T[i] , &T[imin]);
    }

    executionTime = ((double)(clock() - begin)) / CLOCKS_PER_SEC * 1000;
    fprintf(ptrfile,"%d\t%lf\n", length, executionTime);
}
