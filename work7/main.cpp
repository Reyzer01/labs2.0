#include "func.hpp"

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    readMatrix(matrix, n);
    processMatrix(matrix, n);
    writeMatrix(matrix, n);

    return 0;
}
