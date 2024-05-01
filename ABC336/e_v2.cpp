#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// failed when case 110: 11 is not good number, but 110 is good number (divisible by 2)

long calculateDigitSum(long n) {
	long sum = 0;

	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

long removeLastDigits(long n) {
	while (n % 10 == 0) {
		n /= 10;
	}

	return n;
}

long countGoodNumbers(long n) {
	long count = 0;
	vector <long> goodNumbers;


	for (long i = 1; i <= n; i++) {
		cout << "loop " << i << endl;
		int n_lastdigits_removed = removeLastDigits(i);
		cout << n_lastdigits_removed << endl;
		if (n_lastdigits_removed != i) {
			if (find(goodNumbers.begin(), goodNumbers.end(), n_lastdigits_removed) != goodNumbers.end()) {
			// if (n_lastdigits_removed in goodNumbers) {
				count ++;
			}
		} else {
			cout << "else" << endl;
			if (i % calculateDigitSum(i) == 0) {
				count++;
				goodNumbers.push_back(i);
			}
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