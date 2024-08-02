/*
//--------------------------------------------------------------------------------------//
This module contains three different implementations of matrix multiplication. 
The purpose of this module is to use these implementations to explore computer systems concepts. 
By using tools like Perf, Valgrind, and the time command, you can explore what the computer
is doing under the hood when running these implemntations.
E.g memory locality/caching, branch predictability, SIMD registers, etc.
I've written my own analysis in report.txt.
*/
//--------------------------------------------------------------------------------------//
#include <stdint.h>
#include <stdio.h>
#include "./version2-master/version2-master/vectorclass.h"
#include "Eigen/Dense"
//#include "./version2-master/vectorclass.h"
//--------------------------------------------------------------------------------------//

//--------------------------------------------------------------------------------------//
void multiply_basic(
    double** matrix1, //(m x n)
    double** matrix2, //(n x p)
    double** result, //(m x p)
    uint64_t m, 
    uint64_t n, 
    uint64_t p

);
/* 
This function is a "normal implementation" of matrix multiplication. It uses no _
*/
//--------------------------------------------------------------------------------------//

void multiply_smid(
    double** matrix1, //(m x n)
    double** matrix2, //(n x p)
    double** result, //(m x p)
    uint64_t m, 
    uint64_t n, 
    uint64_t p
);
/* This function is an optimized version of a1. It multiplies 
matrix1 by matrix2 and stores the resulting matrix in result. It uses _
*/
//--------------------------------------------------------------------------------------//

void multiply_smid_transpose(
    double** matrix1, //(m x n)
    double** matrix2, //(n x p)
    double** result, //(m x p)
    uint64_t m, 
    uint64_t n, 
    uint64_t p
);
/* This function uses the Vector Class Library for SIMD operations 
https://github.com/vectorclass/version2 by Agner Fog, to perform matrix multiplication. 
*/
//--------------------------------------------------------------------------------------//