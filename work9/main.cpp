#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned long long num = 0x123456789ABCDEF0; // ������ �����

    // ��������� �� ������ ���� �����
    unsigned char* bytePtr = reinterpret_cast<unsigned char*>(&num);

    // ������ ����� � ������
    int numBytes = sizeof(unsigned long long);

    // ����� ����������� ������� �����
    cout << "The contents of the bytes of the number " << hex << num << ":" << endl;
    for (int i = 0; i < numBytes; i++) {
        cout << "Byte " << i << ": 0x" << hex << setw(2) << setfill('0') << static_cast<int>(bytePtr[i]) << endl;
    }

    return 0;
}