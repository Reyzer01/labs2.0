#include <iostream>

// Функция для вычисления суммы цифр числа
int sum_of_digits(int number) {
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    const int N_Max = 10000;
    int numbers[N_Max];
    int n;
    std::cout << std::endl << "Input n ";
    std::cin >> n;
    std::cout << "Input " << n << " values ";
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    bool flag = true;

    // Проверка наличия числа с суммой цифр равной 19
    for (int i = 0; i < n; ++i) {
        if (sum_of_digits(numbers[i]) == 19) {
            flag = false;
            break;
        }
    }


    if (!flag) {
        std::cout << "It has 19." << std::endl;
    }
    else {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (numbers[j] < numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }

        // Вывод отсортированной последовательности
        for (int i = 0; i < n; ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}