#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "matrixMultiplication.h"
#include "Eigen/Dense"

void print_matrix(double** matrix, u_int64_t m, u_int64_t n){
    for(u_int64_t row = 0; row<m; row++){
        for(u_int64_t col = 0; col < n; col++){
            printf("%.6g ", matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

double** initialize_matrix(u_int64_t m, u_int64_t n){
    double** matrix = (double**)malloc(m*sizeof(double*));
    for(u_int64_t row=0; row<m; row++){
        matrix[row] = (double*)malloc(n*sizeof(double));
    }
    return matrix;
}

double** initialize_matrix2(u_int64_t m, u_int64_t n) {
    double** matrix = new double*[m];  // Allocate array of pointers
    for(u_int64_t row = 0; row < m; ++row) {
        matrix[row] = new double[n];  // Allocate array of doubles for each row
    }
    return matrix;
}

void load_matrix(double** matrix, u_int64_t m, u_int64_t n){
    double temp = 0;
    for(u_int64_t row= 0; row < m; row++){
        for(u_int64_t col = 0; col<n; col++){
            matrix[row][col] = temp;
            temp += 1;
            //matrix1[i][x] = ((double)rand() / RAND_MAX - 0.25);
        }
    }
}

void free_matrix(double** matrix, u_int64_t m){
    for(u_int64_t row =0; row < m; row++){
        free(matrix[row]);
    }
    free(matrix);
}

void delete_matrix(double** matrix, u_int64_t m) {
    for (u_int64_t row = 0; row < m; ++row) {
        delete[] matrix[row];  // Deallocate each row
    }
    delete[] matrix;  // Deallocate the array of pointers
}



int main(){
    uint64_t m = 3;
    uint64_t n = 4;
    u_int64_t p = 8;
    double** matrix1 = initialize_matrix(m,n);
    double** matrix2 = initialize_matrix(n,p);
    double** result = initialize_matrix(m,p);
    load_matrix(matrix1, m, n);
    load_matrix(matrix2,n,p);
    print_matrix(matrix1, m, n);
    print_matrix(matrix2,n,p);

    multiply_basic(matrix1,matrix2,result, m, n, p);
    print_matrix(result,m,p);
    multiply_smid_transpose(matrix1, matrix2,result, m,n,p);
    print_matrix(result, m, p);
    free_matrix(matrix1, m);
    free_matrix(matrix2, n);
    free_matrix(result, m);

    
    Eigen::MatrixXd ma(4,4);
    ma << 0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15;
    Eigen::MatrixXd mb(4,2);
    mb << 0, 1,
        2, 3,
        4, 5,
        6, 7;
    std::cout << ma*mb << std::endl;
    


    return 0;
 
    
}



