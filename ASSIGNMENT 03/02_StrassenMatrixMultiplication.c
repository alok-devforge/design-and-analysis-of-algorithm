#include <stdio.h>
#include <stdlib.h>
int **allocateMatrix(int size)
{
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        matrix[i] = malloc(size * sizeof(int));
    return matrix;
}
void freeMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        free(matrix[i]);
    free(matrix);
}
void matOps(int **A, int **B, int **res, int size, int op)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res[i][j] = A[i][j] + op * B[i][j];
}
void strassen(int **A, int **B, int **C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int newSize = size / 2;
    int **subM[10];
    for (int i = 0; i < 10; i++)
        subM[i] = allocateMatrix(newSize);
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            subM[0][i][j] = A[i][j];                     // A11
            subM[1][i][j] = A[i][j + newSize];           // A12
            subM[2][i][j] = A[i + newSize][j];           // A21
            subM[3][i][j] = A[i + newSize][j + newSize]; // A22
            subM[4][i][j] = B[i][j];                     // B11
            subM[5][i][j] = B[i][j + newSize];           // B12
            subM[6][i][j] = B[i + newSize][j];           // B21
            subM[7][i][j] = B[i + newSize][j + newSize]; // B22
        }
    }
    int **M[7];
    for (int i = 0; i < 7; i++)
        M[i] = allocateMatrix(newSize);
    matOps(subM[0], subM[3], subM[8], newSize, 1); // A11 + A22
    matOps(subM[4], subM[7], subM[9], newSize, 1); // B11 + B22
    strassen(subM[8], subM[9], M[0], newSize);     // M1

    matOps(subM[2], subM[3], subM[8], newSize, 1); // A21 + A22
    strassen(subM[8], subM[4], M[1], newSize);     // M2

    matOps(subM[5], subM[7], subM[9], newSize, -1); // B12 - B22
    strassen(subM[0], subM[9], M[2], newSize);      // M3

    matOps(subM[6], subM[4], subM[9], newSize, -1); // B21 - B11
    strassen(subM[3], subM[9], M[3], newSize);      // M4

    matOps(subM[0], subM[1], subM[8], newSize, 1); // A11 + A12
    strassen(subM[8], subM[7], M[4], newSize);     // M5

    matOps(subM[2], subM[0], subM[8], newSize, -1); // A21 - A11
    matOps(subM[4], subM[5], subM[9], newSize, 1);  // B11 + B12
    strassen(subM[8], subM[9], M[5], newSize);      // M6

    matOps(subM[1], subM[3], subM[8], newSize, -1); // A12 - A22
    matOps(subM[6], subM[7], subM[9], newSize, 1);  // B21 + B22
    strassen(subM[8], subM[9], M[6], newSize);      // M7
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = M[0][i][j] + M[3][i][j] - M[4][i][j] + M[6][i][j];
            C[i][j + newSize] = M[2][i][j] + M[4][i][j];
            C[i + newSize][j] = M[1][i][j] + M[3][i][j];
            C[i + newSize][j + newSize] = M[0][i][j] - M[1][i][j] + M[2][i][j] + M[5][i][j];
        }
    }
    for (int i = 0; i < 10; i++)
        freeMatrix(subM[i], newSize);
    for (int i = 0; i < 7; i++)
        freeMatrix(M[i], newSize);
}
void displayMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
int main()
{
    int size;
    printf("Enter size of matrices (power of 2): ");
    scanf("%d", &size);
    int **A = allocateMatrix(size);
    int **B = allocateMatrix(size);
    int **C = allocateMatrix(size);
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &A[i][j]);
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &B[i][j]);
    strassen(A, B, C, size);
    printf("Resultant matrix:\n");
    displayMatrix(C, size);
    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);
}