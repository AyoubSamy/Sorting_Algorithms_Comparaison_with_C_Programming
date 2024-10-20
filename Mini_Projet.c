#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#include "utils.h"

#define MAX_ARRAY_LENGTH 100000

int main()
{

    for (int length = 1000; length <= MAX_ARRAY_LENGTH; length += 1000)
    {
        int temp_array[length];
        int *arry = generate_array(length);

        memcpy(temp_array, arry, length);

        FILE *bubble_file = fopen("BubbleSort.txt", "a");
        FILE *insertion_file = fopen("InsertionSort.txt", "a");
        FILE *merge_file = fopen("MergeSort.txt", "a");
        FILE *quick_file = fopen("QuickSort.txt", "a");

        bubble_sort(temp_array, length, bubble_file);
        insertion_sort(temp_array, length, insertion_file);
        merge_sort(temp_array, length, merge_file);
        quick_sort(temp_array, length, quick_file);

        fclose(bubble_file);
        fclose(insertion_file);
        fclose(merge_file);
        fclose(quick_file);

        free(arry);
    
    }

    FILE *gnuplot = popen("gnuplot -persistent", "w");

    fprintf(gnuplot, "reset\n");

    fprintf(gnuplot, "set title 'Comparison of Sorting Algorithms with Smoothing'\n");
    fprintf(gnuplot, "set xlabel 'Number of Elements'\n");
    fprintf(gnuplot, "set ylabel 'Time (Milliseconds)'\n");
    fprintf(gnuplot, "set logscale y\n");
    fprintf(gnuplot, "plot 'BubbleSort.txt' using 1:2 smooth bezier title 'BubbleSort (Smoothed)' with lines, \\\n");
    fprintf(gnuplot, "'InsertionSort.txt' using 1:2 smooth bezier title 'InsertionSort (Smoothed)' with lines, \\\n");
    fprintf(gnuplot, "'MergeSort.txt' using 1:2 smooth bezier title 'MergeSort (Smoothed)' with lines, \\\n");
    //fprintf(gnuplot, "'QuickSort.txt' using 1:2 smooth csplines title 'QuickSort (Smoothed)' with lines\n");

    fclose(gnuplot);

    remove("BubbleSort.txt");
    remove("InsertionSort.txt");
    remove("MergeSort.txt");
    remove("QuickSort.txt");

    return 0;
}