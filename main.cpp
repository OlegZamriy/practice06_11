#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_M = 10;
const int MAX_N = 10;

void generateMatrix(int matrix[MAX_M][MAX_N], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;   
        }
    }
}

void rotateMatrix(int matrix[MAX_M][MAX_N], int M, int N, int shifts, int direction) {
    shifts = shifts % (M * N);   

    if (shifts < 0) {
        shifts += M * N;
    }

    int newMatrix[MAX_M][MAX_N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int newRow, newCol;

            if (direction == 1) {   
                newRow = i;
                newCol = (j + shifts) % N;
            }
            else if (direction == 2) {   
                newRow = i;
                newCol = (j - shifts + N) % N;
            }
            else if (direction == 3) {  
                newRow = (i + shifts) % M;
                newCol = j;
            }
            else if (direction == 4) {   
                newRow = (i - shifts + M) % M;
                newCol = j;
            }

            newMatrix[newRow][newCol] = matrix[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_M][MAX_N], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));   

    int M, N;
    cout << "Enter the number of rows (M): ";
    cin >> M;
    cout << "Enter the number of columns (N): ";
    cin >> N;

    int matrix[MAX_M][MAX_N];

    generateMatrix(matrix, M, N);

    cout << "Generated matrix:" << endl;
    printMatrix(matrix, M, N);

    int shifts, direction;
    cout << "Enter the number of shifts: ";
    cin >> shifts;
    cout << "Enter the direction (1 - left, 2 - right, 3 - down, 4 - up): ";
    cin >> direction;

    rotateMatrix(matrix, M, N, shifts, direction);

    cout << "Result after cyclic shift:" << endl;
    printMatrix(matrix, M, N);

    return 0;
}
