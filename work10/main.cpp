#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура узла односвязного списка
struct Node {
    int data;
    Node* next;
};

// Функция для добавления узла в начало списка
Node* addNode(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Функция для печати списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Функция для проверки на палиндром
bool isPalindrome(int n) {
    string s = to_string(n);
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

// Функция для извлечения первой цифры
int getFirstDigit(int n) {
    return to_string(n)[0] - '0';
}

// Функция для извлечения последней цифры
int getLastDigit(int n) {
    return to_string(n).back() - '0';
}


int main() {
    vector<int> sequence;
    int num;

    cout << "Enter a sequence of natural numbers (enter 0 to complete):" << endl;
    while (cin >> num && num != 0) {
        sequence.push_back(num);
    }

    Node* head = nullptr;
    for (int x : sequence) {
        head = addNode(head, x);
    }


    bool orderedByFirstDigit = true;
    bool orderedByLastDigit = true;
    Node* current = head;
    if (current != nullptr && current->next != nullptr) {
        int prevFirst = getFirstDigit(current->data);
        int prevLast = getLastDigit(current->data);
        current = current->next;
        while (current != nullptr) {
            int curFirst = getFirstDigit(current->data);
            int curLast = getLastDigit(current->data);
            if (prevFirst < curFirst) orderedByFirstDigit = false;
            if (prevLast < curLast) orderedByLastDigit = false;
            prevFirst = curFirst;
            prevLast = curLast;
            current = current->next;
        }
    }


    if (orderedByFirstDigit || orderedByLastDigit) {
        Node* newHead = nullptr;
        current = head;
        while (current != nullptr) {
            if (to_string(current->data).length() > 1) {
                if (isPalindrome(current->data)) {
                    newHead = addNode(newHead, current->data);
                    newHead = addNode(newHead, current->data);
                }
                else {
                    newHead = addNode(newHead, current->data);
                }
            }
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = newHead;

    }
    else {
        vector<pair<int, int>> seqWithFirstDigit;
        current = head;
        while (current != nullptr) {
            seqWithFirstDigit.push_back({ getFirstDigit(current->data), current->data });
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        sort(seqWithFirstDigit.begin(), seqWithFirstDigit.end());
        head = nullptr;
        for (const auto& p : seqWithFirstDigit) {
            head = addNode(head, p.second);
        }
    }

    printList(head);


    // Освобождение памяти
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
