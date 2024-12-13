#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// Adds a node to the end of the list
Node* addNode(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) return newNode;
    Node* current = head;
    while (current->next != nullptr) current = current->next;
    current->next = newNode;
    return head;
}


//Checks if a number is a palindrome
bool isPalindrome(int n) {
    string s = to_string(n);
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

//Gets the first digit of a number
int getFirstDigit(int n) {
    if (n == 0) return 0;
    string s = to_string(n);
    return s[0] - '0';
}

//Gets the last digit of a number
int getLastDigit(int n) {
    if (n == 0) return 0;
    string s = to_string(n);
    return s.back() - '0';
}

//Prints the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << (current->next ? " " : "");
        current = current->next;
    }
    cout << endl;
}

//Deletes the linked list
void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    vector<int> inputSequence;
    int num;

    int count;
    cout << "Enter the number of natural numbers in the sequence: ";
    cin >> count;


    for (int i = 0; i < count; ++i) {
        int num;
        cin >> num;
        inputSequence.push_back(num);
    }


    if (inputSequence.empty()) {
        cout << "Empty sequence." << endl;
        return 0;
    }


    bool orderedByFirst = true;
    bool orderedByLast = true;
    for (size_t i = 1; i < inputSequence.size(); ++i) {
        if (getFirstDigit(inputSequence[i - 1]) < getFirstDigit(inputSequence[i])) orderedByFirst = false;
        if (getLastDigit(inputSequence[i - 1]) < getLastDigit(inputSequence[i])) orderedByLast = false;
    }

    Node* head = nullptr;
    if (orderedByFirst || orderedByLast) {
        for (int n : inputSequence) {
            string s = to_string(n);
            if (s.length() > 1) { //Only consider numbers with more than one digit
                head = addNode(head, n);
                if (isPalindrome(n)) head = addNode(head, n); // Duplicate palindromes
            }
        }
    }
    else {
        vector<pair<int, int>> seqWithFirstDigit;
        for (int n : inputSequence) {
            seqWithFirstDigit.push_back({ getFirstDigit(n), n });
        }
        sort(seqWithFirstDigit.begin(), seqWithFirstDigit.end());
        for (const auto& p : seqWithFirstDigit) {
            head = addNode(head, p.second);
        }
    }

    printList(head);
    deleteList(head);

    return 0;
}
