#include <iostream>
using namespace std;

int countTrailingZero (int n) {
	int count = 0;

	while ((n & 1) == 0 && n != 0) {
		count++;
		n >>= 1;
	}

	return count;
}

int main() {
	int N;
	cin >> N;
	cout << countTrailingZero(N) << endl;
	return 0;
}