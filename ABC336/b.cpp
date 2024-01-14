#include <iostream>

using namespace std;

int countTrailingZero (int N) {
	int count = 0;
	while (N > 0) {
		N /= 2;
		count += N;
	}
	return count;
}


int main() {
	int N;
	cin >> N;
	cout << countTrailingZero(N) << endl;
	return 0;
}