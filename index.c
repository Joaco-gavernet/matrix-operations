#include <stdio.h>
#include <stdlib.h>

#define DIM 10
#define AM 2
#define AN 2
#define BM 2
#define BN 2

#define forn(i, n) for (i = 0; i < n; i++)


void printMatrix (int matrix[][DIM], int m, int n) {
    int i,j;
    forn(i,m) {
        forn(j, n) printf("%3d ", matrix[i][j]);
        printf("\n");
    }
    printf("//////////////\n");
}

int * productoDefinido (int am, int an, int bm, int bn) {
    int result[2];
    if (an == bm) {
        result[0] = am;
        result[1] = bn;
    } else {
        result[0] = 0;
        result[1] = 0;
    }

    return result;
}

int * productoMatrices (int a[][DIM], int b[][DIM], int result[DIM][DIM], int am, int an, int bm, int bn) {
    int i = 0, j = 0;
    while (i < am) {
        int k = 0;
        while (k < an) {
            result[i][j] += a[i][k] * b[k][j];
            k++;
        }
        if (j < an) j++;
        else {
            j = 0;
            i++;
        }
    }
}



int main()
{
    int matrizA[DIM][DIM] = {{1, 2}, {3, 4}};
    int matrizB[DIM][DIM] = {{5, 6}, {7, 8}};
    int resultado[DIM][DIM] = {0};
    int *dimension_resultado;

    printMatrix(matrizA, AM, AN);
    printMatrix(matrizB, BM, BN);

    productoMatrices(matrizA, matrizB, resultado, AM, AN, BM, BN);
    dimension_resultado = productoDefinido(AM, AN, BM, BN);
    printMatrix(resultado, dimension_resultado[0], dimension_resultado[1]);

    


//    int *defined;
//    defined = productoDefinido(3, 3, 3, 3);
//    printf("producto definido? -> %d", defined[0]);

    return 0;
}
