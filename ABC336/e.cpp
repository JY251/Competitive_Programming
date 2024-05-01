#include <iostream>
using namespace std;

long calculateDigitSum(long n) {
	long sum = 0;

	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

long countGoodNumbers(long n) {
	long count = 0;

	for (long i = 1; i <= n; i++) {
		if (i % calculateDigitSum(i) == 0) {
			count++;
		}
	}

	return count;
}

int main() {
	long N;
	cin >> N;

	cout << countGoodNumbers(N) << endl;
	return 0;
}