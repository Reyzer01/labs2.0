#include <iostream>
using namespace std;
int main() {
    const int MAX_SIZE = 10000;
    int n;
    int arr[MAX_SIZE];

    cout << "Input (n <= 10000): ";
    cin >> n;

    cout << "Input a sequence of numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // �������� �����, ������������ � ��������������� ����� � ��� �� ������
    int newArr[MAX_SIZE];
    int newSize = 0;

    for (int i = 0; i < n; ++i) {
        int firstDigit = arr[i];
        while (firstDigit >= 10) {
            firstDigit /= 10; // �������� ������ �����
        }

        int lastDigit = arr[i] % 10; // �������� ��������� �����

        if (firstDigit != lastDigit) {
            newArr[newSize++] = arr[i]; // ��������� �����, ���� ��� �� �������� ��� �������
        }
    }

    // ������������ �����, ������������ � ����� 3
    int finalArr[MAX_SIZE * 2]; // ������ ��� �������� ��������� ������������������
    int finalSize = 0;

    for (int i = 0; i < newSize; ++i) {
        finalArr[finalSize++] = newArr[i]; // ��������� ������������ �����

        // ���������, ���������� �� ����� � 3
        int temp = newArr[i];
        while (temp >= 10) {
            temp /= 10;
        }

        if (temp == 3) {
            finalArr[finalSize++] = newArr[i]; // ��������� �����
        }
    }

    // ����� ��������� ������������������
    for (int i = 0; i < finalSize; ++i) {
        cout << finalArr[i] << " ";
    }
    cout << endl;

    return 0;
}