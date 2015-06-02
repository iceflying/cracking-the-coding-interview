/*
 * Author: Xin Quan <quanxin1991@163.com>
 */

#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int n){
    int layer;
    int first, last, shift;
    int tmp;
    for (layer = 0; layer < n / 2; ++layer){
        for (shift = 0; shift < n - 1 - layer; ++shift){
            first = layer;
            last = n - 1 - layer;
            tmp = matrix[first][first + shift];
            matrix[first][first + shift] = matrix[first + shift][last];
            matrix[first + shift][last] = matrix[last][last - shift];
            matrix[last][last - shift] = matrix[last - shift][first];
            matrix[last - shift][first] = tmp;
        }
    }
}

void print_matrix(int **matrix, int n){
    int i, j;
    for (i=0; i<n; ++i){
        for (j=0; j<n; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void test(void (*func4test)(int **, int), int **matrix, int n){
    printf("The original matrix is :\n");
    print_matrix(matrix, n);
    rotate(matrix, n);
    printf("The rotated matrix is :\n");
    print_matrix(matrix, n);
}

int main(){
    int **matrix, n = 3;
    int i, j;
    matrix = (int **)malloc(sizeof(*matrix) * n);
    for (i=0; i<n; ++i){
        matrix[i] = (int *)malloc(sizeof(**matrix) * n);
    }
    for (i=0; i<n; ++i){
        for (j=0; j<n; ++j){
            matrix[i][j] = i * n + j;
        }
    }
    test(rotate, (int **)matrix, 3);
    return 0;
}
