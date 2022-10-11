#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
//#include "geek.h"

void swapInt(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void swapDbl(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int** array, int row, int col) {
    int length = row * col;
    for (size_t i = 0; i < length; ++i)
    {
        for (size_t j = 0; j < length-1; ++j)
        {
            int Row = j / col;
            int Column = j % col;
            int nextRow = (j + 1) / col;
            int nextColumn = (j + 1) % col;

            if (array[Row][Column] > array[nextRow][nextColumn])
                swapInt(&array[Row][Column], &array[nextRow][nextColumn]);
        }   
    }
}


int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);

}
void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}
int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}
void print2dIntArray(int** array, const int row, const int col, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(format, get2dInt(array, i, j));
        }
        printf("\n");
    }
}
void fill2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int value = ((i + 1) * (j + 1));
            //int value = rand() % 100;
            set2dInt(array, i, j, value);
        }
    }
}

void printDblArray(double* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void reverse(double* sequence, int size) {
    printDblArray(sequence, size, 2);
    for (int i = 0; i < size / 2; ++i) {
         swapDbl(&sequence[i], &sequence[size - i - 1]);
    }
    printf("\n");
    printDblArray(sequence, size, 2);
}

void math(double* sequence, int size) {
    
    for (int i = 0; i < size; ++i) {
        double x = sqrt(fabs(sequence[i])) + 5 * pow(sequence[i], 3);

        x > 400
          ? printf(" %d. Number %lf (of %.1lf) bigger than 400\n", i + 1, x, sequence[i])
          : printf(" %d. %lf\n", i + 1, x);
    }
}

void enter(double *seq, int size) {
    printf("Enter %d :\n", size);
    for (int i = 0; i < size; ++i) {
        printf("num %02d: ", i  + 1);
        scanf("%lf", &seq[i]);
    }
}

void trabbPradoKnuth() {
    const int size = 11;
    double sequence[size];
    enter(sequence, size);
    reverse(sequence, size);
    math(sequence, size);
}



int main() {

    int** arrTwo = init2dIntArray(arrTwo, 3, 3);
    //fill2dIntArray(arrTwo, 3, 3)
    set2dInt(arrTwo, 0, 0, 3); set2dInt(arrTwo, 0, 1, 9);
    set2dInt(arrTwo, 0, 2, 6); set2dInt(arrTwo, 1, 0, 5);
    set2dInt(arrTwo, 1, 1, 2); set2dInt(arrTwo, 1, 2, 6);
    set2dInt(arrTwo, 2, 0, 8); set2dInt(arrTwo, 2, 1, 5);
    set2dInt(arrTwo, 2, 2, 1);
    print2dIntArray(arrTwo, 3, 3, 6);
    bubbleSort(arrTwo, 3, 3);
    printf("\n");
    print2dIntArray(arrTwo, 3, 3, 6);
    printf("\n");


    trabbPradoKnuth();  

    return 0;
}