#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 100;

int main() {
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];

    // Ââîä ðàçìåðîâ ìàòðèöû
    cout << "Input the number of rows (n): ";
    cin >> n;
    cout << "Input the number of columns (m): ";
    cin >> m;

    // Ââîä ýëåìåíòîâ ìàòðèöû
    cout << "Input matrix elements:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> A[i][j];
        }
    }

    int max_row_index = 0;
    int max_row_sum = 0;

    // Ïîèñê ñòðîêè ñ íàèáîëüøåé ïî àáñîëþòíîé âåëè÷èíå ñóììîé
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

    // Çàìåíà ýëåìåíòîâ íàéäåííîé ñòðîêè íà 9999
    for (int j = 0; j < m; ++j) {
        A[max_row_index][j] = 9999;
    }

    // Âûâîä èçìåíåííîé ìàòðèöû
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}