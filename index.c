#include <stdio.h>
#include <stdlib.h>

#define DIM 10
#define AM 3
#define AN 3
#define BM 3
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

int sumaDefinida(int am, int an, int bm, int bn) {
    return (am == bm) && (an == bn);
}

void sumarMatrices (const int A[][DIM], const int B[][DIM], int C[][DIM], int m, int n) {
    int i,j;
    forn(i,m) forn(j,n) C[i][j] = A[i][j] + B[i][j];
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
    int matrizA[DIM][DIM] = {{1, 2, 3}, {1, 0, -1}, {1, 1, 1}};
    int matrizB[DIM][DIM] = {{1, 2}, {2, 1}, {1, 1}};
    int resultado[DIM][DIM] = {0};
    int *dimension_resultado; // dimension de matriz resultado de producto

    printMatrix(matrizA, AM, AN);
    printMatrix(matrizB, BM, BN);

    productoMatrices(matrizA, matrizB, resultado, AM, AN, BM, BN);
    dimension_resultado = productoDefinido(AM, AN, BM, BN);
    printf("Producto: ");
    printMatrix(resultado, dimension_resultado[0], dimension_resultado[1]);

    if (sumaDefinida(AM, AN, BM, BN)) {
        sumarMatrices(matrizA, matrizB, resultado, AM, AN);
        printMatrix(resultado, AM, AN);
    }


    return 0;
}
