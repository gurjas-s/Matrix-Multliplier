#include "matrixMultiplication.h"

//(m x n)*(n x p) = (m x p)

void multiply_basic(double** matrix1, double** matrix2, double** __restrict result, uint64_t m, uint64_t n, uint64_t p){
    
    for(uint64_t row=0; row<m; row++){
        for(uint64_t times=0; times<p; times++){
            for(uint64_t col=0; col<n; col++){
                result[row][times] += matrix1[row][col]*matrix2[col][times];
            }
            //printf("%.6g", sum);
   
        }
    }
}

void multiply_smid(double** matrix1, double** matrix2, double** __restrict result, uint64_t m, uint64_t n, uint64_t p){
    
    for(uint64_t row=0;row<m;row++){
        for(uint64_t times=0; times<p; times++){
            Vec4d c = 0.0;
            for(uint64_t col=0; col<n; col+=4){
                
                    Vec4d a = Vec4d().load(&matrix1[row][col]);
                    Vec4d b = {matrix2[col][times], matrix2[col+1][times], matrix2[col+2][times], matrix2[col+3][times]};
                    c += a*b;
            }
            
            result[row][times] = horizontal_add(c);
        
        }
    }
    return;
}
 
void multiply_smid_transpose(double** matrix1, double** matrix2, double** __restrict result, uint64_t m, uint64_t n, uint64_t p){
    //a.load(matrix1[1]);
    //Vec4d b = {matrix1[0][0], matrix1[1][0], matrix1[2][0], matrix1[3][0]};
    //double c = horizontal_add(b);
    //std::cout << c << std::endl;

    double** transposed = (double**)malloc(p * sizeof(double*));
    for (uint64_t row = 0; row < p; row++) {
        transposed[row] = (double*)malloc(n * sizeof(double));
    }

    // Transpose matrix2
    for (uint64_t row = 0; row < n; ++row) {
        for (uint64_t col = 0; col < p; ++col) {
            transposed[col][row] = matrix2[row][col];
        }
    }
    
    for(uint64_t row=0;row<m;row++){
        for(uint64_t times=0; times<p; times++){
            Vec4d c = 0.0;
            for(uint64_t col=0; col<n; col+=4){
                
                    Vec4d a = Vec4d().load(&matrix1[row][col]);
                    Vec4d b = Vec4d().load(&transposed[times][col]);
                    c += a*b;
            }
            
            result[row][times] = horizontal_add(c);
        
        }
    }
    
    return;

}

