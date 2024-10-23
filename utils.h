/*ce fichier sert a assurer la modularite du projet ainsi d'eviter les erreurs de compilation et la redondance */

#ifndef UTILS_H
#define UTILS_H
/*declaration des fonction utiliser dans le fichier "utils.c" */
int* generate_array(int length);
void print_arr(char statement[],int arr[], int length);
#endif