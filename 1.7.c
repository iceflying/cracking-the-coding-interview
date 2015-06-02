/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int BOOLEAN;

void set_zeros(int **matrix, int m, int n){
    BOOLEAN *row, *col;
    int i, j;
    row = (BOOLEAN *)malloc(sizeof(*row) * m);
    memset(row, 0, sizeof(*row) * m);
    col = (BOOLEAN *)malloc(sizeof(*col) * n);
    memset(row, 0, sizeof(*col) * n);
    for (i=0; i<m; ++i){
        for (j=0; j<n; ++j){
            if (matrix[i][j] == 0){
                row[i] = TRUE;
                col[j] = TRUE;
            }
        }
    }
    for (i=0; i<m; ++i){
        if (row[i] == TRUE){
            for (j=0; j<n; ++j){
                matrix[i][j] = 0;
            }
        }
    }
    for (j=0; j<n; ++j){
        if (col[j] == TRUE){
            for (i=0; i<n; ++i){
                matrix[i][j] = 0;
            }
        }
    }
}

void print_matrix(int **matrix, int m, int n){
    int i, j;
    for (i=0; i<m; ++i){
        for (j=0; j<n; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void test(void (*func4test)(int **, int, int), int **matrix, int m, int n){
    printf("The original matrix is :\n");
    print_matrix(matrix, m, n);
    set_zeros(matrix, m, n);
    printf("The converted matrix is :\n");
    print_matrix(matrix, m, n);
}

int main(){
    int **matrix, m = 3, n = 4;
    int i, j;
    matrix = (int **)malloc(sizeof(*matrix) * m);
    for (i=0; i<n; ++i){
        matrix[i] = (int *)malloc(sizeof(**matrix) * n);
    }
    for (i=0; i<m; ++i){
        for (j=0; j<n; ++j){
            matrix[i][j] = i * n + j;
        }
    }
    matrix[1][2] = 0;
    test(set_zeros, matrix, m, n);
    return 0;
}
