#include "iostream"

using namespace std;

int main()
{
	int x;
	int i;
	cin >> x >> i;
if (x <= 0 || x >= 1000000000) {
    return 1;
}

if(i > 32)
{
  return 1;
}
	x |= (0 << i);
	cout << x << endl;

	return 0;
}