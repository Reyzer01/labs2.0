#include <iostream>

using namespace std;


bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


int countPrimes(int row[], int cols) {
    int count = 0;
    for (int j = 0; j < cols; j++) {
        if (isPrime(row[j])) {
            count++;
        }
    }
    return count;
}


void findMaxAndCount(int arr[][100], int n, int& maxVal, int& maxCount) {
    maxVal = arr[0][0];
    maxCount = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == maxVal) {
                maxCount++;
            }
        }
    }
}


bool compare(const pair<int, int>& a, const pair<int, int>& b, int arr[][100]) {
    return countPrimes(arr[a.first], b.second) > countPrimes(arr[b.first], b.second);
}


void sortRows(int arr[][100], int n, int maxVal, int maxCount) {
    pair<int, int> rows[100];


    for (int i = 0; i < n; i++) {
        rows[i] = { i, countPrimes(arr[i], n) };
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rows[i].second < rows[j].second) {
                swap(rows[i], rows[j]);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[rows[i].first][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[100][100];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int maxVal, maxCount;
    findMaxAndCount(arr, n, maxVal, maxCount);


    if (maxCount > 1) {
        sortRows(arr, n, maxVal, maxCount);
    }
    else {
        cout << "It has no second max element." << endl;
    }

    return 0;
}