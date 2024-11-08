#include <iostream>

using namespace std;

// Функция для вычисления суммы цифр числа
int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Функция для получения первой цифры числа
int firstDigit(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}


int main() {
    const int MAX_N = 1000;
    int arr[MAX_N];
    int n;

    cout << "Input (n <= 1000): ";
    cin >> n;

    // Ввод последовательности чисел
    cout << "Input " << n << " numbers ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int sum1 = sumOfDigits(arr[j]);
            int sum2 = sumOfDigits(arr[j + 1]);
            int first1 = firstDigit(arr[j]);
            int first2 = firstDigit(arr[j + 1]);


            if (sum1 > sum2 ||
                (sum1 == sum2 && first1 > first2) ||
                (sum1 == sum2 && first1 == first2 && arr[j] > arr[j + 1])) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Вывод отсортированной последовательности
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}