#include <iostream>
#include <vector>
using namespace std;

bool isGoodNumber(int n) {
	while (n > 0) {
		int digit = n % 10;
		if (digit % 2 != 0) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	int N;
	cin >> N;

	vector<int> goodNumbers;
	int currentNumber = 0;

	while(goodNumbers.size() < N) {
		if (isGoodNumber(currentNumber)) {
			goodNumbers.push_back(currentNumber);
		}
	}

	cout << goodNumbers[N - 1] << endl;
	return 0;
}