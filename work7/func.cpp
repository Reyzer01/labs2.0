#include "func.hpp"
#include <iostream>
#include <algorithm>

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& n) {
    std::cout << "Enter the dimension of the matrix n (n <= 100): ";
    std::cin >> n;

    std::cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void processMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int maxElement = matrix[0][0];
    // Максимальный элемент
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }

    // Проверка на наличие второго максимального элемента
    bool hasDuplicateMax = false;
    for (int i = 0; i < n && !hasDuplicateMax; ++i) {
        for (int j = 0; j < n && !hasDuplicateMax; ++j) {
            if (matrix[i][j] == maxElement) {
                hasDuplicateMax = true;
            }
        }
    }

    // Упорядочивание строки по количеству простых чисел
    if (hasDuplicateMax) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (countPrimes(matrix[i], n) < countPrimes(matrix[j], n)) {
                    // Меняем строки местами
                    for (int k = 0; k < n; ++k) {
                        std::swap(matrix[i][k], matrix[j][k]);
                    }
                }
            }
        }
    }
}

void writeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    std::cout << "Результат:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int countPrimes(const int row[MAX_SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (isPrime(row[i])) {
            count++;
        }
    }
    return count;
}

