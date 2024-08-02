#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "matrixMultiplication.h"
#include "tests.cpp"



#define TIMING_RESULT(DESCR, CODE) do { \
    struct timespec start, end; \
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); \
    CODE; \
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); \
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9; \
    printf("%25s took %7.1f ms\n", descr, elapsed * 1000); \
} while(0)


void time_basic(const char* descr, void multiply_basic(double**, double**, double**, u_int64_t, u_int64_t, u_int64_t), u_int64_t m, u_int64_t n, u_int64_t p){

    double** matrix1 = initialize_matrix(m,n);
    double** matrix2 = initialize_matrix(n,p);
    double** result = initialize_matrix(m,p);
    load_matrix(matrix1, m, n);
    load_matrix(matrix2,n,p);

    TIMING_RESULT(descr, multiply_basic(matrix1, matrix2, result, m,n,p));
}

void time_smid(const char* descr, void multiply_smid(double**, double**, double**, u_int64_t, u_int64_t, u_int64_t), u_int64_t m, u_int64_t n, u_int64_t p){

    double** matrix1 = initialize_matrix(m,n);
    double** matrix2 = initialize_matrix(n,p);
    double** result = initialize_matrix(m,p);
    load_matrix(matrix1, m, n);
    load_matrix(matrix2,n,p);

    TIMING_RESULT(descr, multiply_smid(matrix1, matrix2, result, m,n,p));
}

void time_smid_transpose(const char* descr, void multiply_smid_transpose(double**, double**, double**, u_int64_t, u_int64_t, u_int64_t), u_int64_t m, u_int64_t n, u_int64_t p){

    double** matrix1 = initialize_matrix(m,n);
    double** matrix2 = initialize_matrix(n,p);
    double** result = initialize_matrix(m,p);
    load_matrix(matrix1, m, n);
    load_matrix(matrix2,n,p);

    TIMING_RESULT(descr, multiply_smid_transpose(matrix1, matrix2, result, m,n,p));
}

int main(){
    time_basic("Basic timing: ", multiply_basic, 788, 800, 1200);
    time_smid("SMID timing: ", multiply_smid, 788, 800, 1200);
    time_smid_transpose("Eigen timing: ", multiply_smid_transpose, 788, 800, 1200);
    return 0;
}
