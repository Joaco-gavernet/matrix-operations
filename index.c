#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 10
#define AM 4
#define AN 4
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

void printMatrixFloat (float matrix[][DIM], int m, int n) {
    int i,j;
    forn(i,m) {
        forn(j, n) printf("%.2f ", matrix[i][j]);
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

int * submatriz(int a[][DIM], int x, int y, int n) {
    int i = 0; // fila matriz parametro
    int resultado[DIM][DIM];
    int u = 0; // fila matriz resultado

    while (i < n) {
        int j = 0; // columna matriz parametro
        int v = 0; // columna matriz resultado

        if (i != x) {
            while (j < n) {
                if (j != y) {
                    resultado[u][v] = a[i][j];
                    v++;
                }
                j++;
            }
            u++;
        }

        i++;
    }
    return resultado;
}

int determinante (int a[][DIM], int n) {

    if (n != 1) { // no es base case
        int j = 0;
        int resultado = 0;

        while (j < n) {
            resultado += a[0][j] * pow((-1), j) * determinante(submatriz(a, 0, j, n), (n - 1));
            j++;
        }
        return resultado;
    }

    return a[0][0];
}

int * calcularInversa (int a[][DIM], float result[][DIM], int n) {
    int i = 0;
    int detA = determinante(a, n);

    while (i < n) {
        int j = 0;

        while (j < n) {
            if (i == 0) {
                printMatrix(submatriz(a, j, i, n), (n - 1), (n - 1));
            }
            int auxDet = determinante(submatriz(a, j, i, n), (n - 1));
            result[i][j] = (float) (pow((-1), (i + j)) * auxDet) / detA;
            j++;
        }

        i++;
    }

    return result;
}

void permutacion (int arr[][DIM], int first, int second, int n) {
    int i;
    int aux[DIM];
    forn(i, n + 1) aux[i] = arr[first][i];
    forn(i, n + 1) arr[first][i] = arr[second][i];
    forn(i, n + 1) arr[second][i] = aux[i];
    //n + 1 para que cambie tambien la igualdad
}

void eliminacionGaussiana (int arr[][DIM], int m, int n) {
    int i = 0;
    int k;

    while (i < m) {  //se fijs si no llego a la ultima fila
        if (arr[i][i] != 1) {     //Se fija si  el pivote no es 1
            if (arr[i][i] == 0) {   //Si el pivote es 0, busca permutacion
                int k = i;
                while (k < m) {
                    if (arr[k][i] != 0) {          //Si encuentra un elemento de la columna que no sea
                        permutacion(arr, i, k, n); // 0, entonces permuta, sino termina la funcion
                        break;
                    }
                    k++;
                }
                if (k == m) break;
            }
            int divisor = arr[i][i];
            forn(k, n) arr[i][k] /= divisor; //divide la fila del pivote por el pivote (para que
                                            //  quede 1)
        }

        int w = i + 1;
        while (w < m) {                                      //mientras no llegue a la ultima fila
            int coeficiente = arr[w][i];                     //resta al seleccionado por la anterior
            forn(k, n) arr[w][k] -= coeficiente * arr[i][k]; //fila * el coeficiente del seleccionado
            w++;
        }

        i++;
    }

}

int esCompatible (int a[][DIM], int m, int n) {
    int k;

    eliminacionGaussiana(a, m, n);

    if (a[m - 1][n - 2] == 0) {
        if (a[m - 1][n - 1] != 0) return 0;
        else return 1;
    } else return 2;

}

int main()
{
//    int matrizA[DIM][DIM] = {{1, 0, 2}, {-3, 4, 6}, {-1, -2, 3}};
//    int matrizB[DIM][DIM] = {{1, 2}, {2, 1}, {1, 1}};
//    float resultado[DIM][DIM] = {0};
//    int *dimension_resultado; // dimension de matriz resultado de producto

//    printMatrix(matrizA, AM, AN);
//    calcularInversa(matrizA, resultado, AM);
//    printf("resultado: \n");
//    printMatrixFloat(resultado, AM, AM);

//    int detA = determinante(matrizA, AM);
//    printf("detA: %d", detA);

//    printMatrix(matrizB, BM, BN);

//    productoMatrices(matrizA, matrizB, resultado, AM, AN, BM, BN);
//    dimension_resultado = productoDefinido(AM, AN, BM, BN);
//    printf("Producto: ");
//    printMatrix(resultado, dimension_resultado[0], dimension_resultado[1]);
//
//    if (sumaDefinida(AM, AN, BM, BN)) {
//        sumarMatrices(matrizA, matrizB, resultado, AM, AN);
//        printMatrix(resultado, AM, AN);
//    }


    int matrizAsociada[DIM][DIM] = {{0, 4, 1, 20}, {2, -2, 1, 0}, {1, 0, 1, 5}, {1, 1, -1, 10}};
    // int matrizAsociada[DIM][DIM] = {{1, 0, 2, 3}, {2, 0, 5, 7}};
    // int matrizAsociada[DIM][DIM] = {{0}, {0}};

    eliminacionGaussiana(matrizAsociada, AM, AN);
    printMatrix(matrizAsociada, AM, AN);
    printf("esCompatible: %d", esCompatible(matrizAsociada, AM, AN));

    return 0;
}
