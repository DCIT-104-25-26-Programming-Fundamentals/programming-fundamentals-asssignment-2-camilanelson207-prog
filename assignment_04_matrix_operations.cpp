// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void showMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transpose(int mat[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int rowsA, int colsA, int colsB, int result[MAX][MAX]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum = sum + a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int mat[MAX][MAX], transposed[MAX][MAX];
    int rows, cols;

    cout << "=== PART A: Transpose a Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the matrix elements:" << endl;
    readMatrix(mat, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    showMatrix(mat, rows, cols);

    transpose(mat, rows, cols, transposed);

    cout << "\nTransposed Matrix:" << endl;
    showMatrix(transposed, cols, rows);

    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    int addRows, addCols;
    cout << "Enter number of rows: ";
    cin >> addRows;
    cout << "Enter number of columns: ";
    cin >> addCols;

    int matA[MAX][MAX], matB[MAX][MAX], sumResult[MAX][MAX];

    cout << "Enter elements of Matrix A:" << endl;
    readMatrix(matA, addRows, addCols);

    cout << "Enter elements of Matrix B:" << endl;
    readMatrix(matB, addRows, addCols);

    addMatrix(matA, matB, addRows, addCols, sumResult);

    cout << "\nSum of Matrices:" << endl;
    showMatrix(sumResult, addRows, addCols);

    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return 0;
    }

    int matC[MAX][MAX], matD[MAX][MAX], productResult[MAX][MAX];

    cout << "Enter elements of Matrix A:" << endl;
    readMatrix(matC, rowsA, colsA);

    cout << "Enter elements of Matrix B:" << endl;
    readMatrix(matD, rowsB, colsB);

    multiplyMatrix(matC, matD, rowsA, colsA, colsB, productResult);

    cout << "\nProduct of Matrices (A x B):" << endl;
    showMatrix(productResult, rowsA, colsB);

    return 0;
}