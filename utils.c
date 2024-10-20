#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

void print_arr(char statement[],int arr[], int length){
    printf("%s:\t\t", statement);
    for (int i = 0; i < length; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int* generate_array(int length){
    int *parr = malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
    {   
        *(parr + i) = rand(); 
    } 

    return parr;
}