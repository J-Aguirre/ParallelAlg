#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

void create_m(int** &matriz, int filas, int colum){
    matriz = new int*[filas];
    for(int i=0; i<filas; i++)
        matriz[i] = new int[colum];
}

int** strassen(int** matriz_1, int** matriz_2, int filas, int colum){
    int** m_result;
    int* M = new int[7]
    create_m(m_result);
    for(int i=0; i<filas; i++)
        for(int j=0; j<colum; j++)
}


int main(){
    return 0;
}

/* -------------

A 1 2     B 1 2
1 1 2     1 5 6
2 3 4     2 7 8

(2-4)*(7+8)

------------ */