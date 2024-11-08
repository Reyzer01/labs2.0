#include <iostream>
#include <cstdlib>

const int MAX_SIZE = 100;

int main() {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];

    // Ввод размеров матрицы
    std::cout << "Input the number of rows (n): ";
    std::cin >> n;
    std::cout << "Input the number of columns (m): ";
    std::cin >> m;

    // Ввод элементов матрицы
    std::cout << "Input matrix elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> A[i][j];
        }
    }

    int max_row_index = 0;
    int max_row_sum = 0;

    // Поиск строки с наибольшей по абсолютной величине суммой
    for (int i = 0; i < n; ++i) {
        int current_row_sum = 0;
        for (int j = 0; j < m; ++j) {
            current_row_sum += std::abs(A[i][j]);
        }
        if (current_row_sum > max_row_sum) {
            max_row_sum = current_row_sum;
            max_row_index = i;
        }
    }

    // Замена элементов найденной строки на 9999
    for (int j = 0; j < m; ++j) {
        A[max_row_index][j] = 9999;
    }

    // Вывод измененной матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}