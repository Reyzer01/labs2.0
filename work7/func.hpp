#ifndef FUNC_HPP
#define FUNC_HPP

const int MAX_SIZE = 100; // Максимальный размер матрицы

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& n);
void processMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n);
void writeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n);
bool isPrime(int number);
int countPrimes(const int row[MAX_SIZE], int size);

#endif // FUNC_HPP
