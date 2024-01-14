#include <iostream>
#include <vector>
using namespace std;

vector<int> decimalToQuinary(long decimalNumber) {
	vector<int> quinaryDigits;

	while(decimalNumber > 0) {
		int remainder = decimalNumber % 5;
		quinaryDigits.insert(quinaryDigits.begin(), remainder);
		decimalNumber /= 5;
	}

	if (quinaryDigits.empty()) {
		quinaryDigits.push_back(0);
	}

	return quinaryDigits;
}

int main() {
	long N;
	cin >> N;

	vector<int> quinaryDigits = decimalToQuinary(N-1);
	vector<int> goodNumbers;

	// vector<int>::iterator i;
	vector<int>::size_type i;

	for (i = 0; i < quinaryDigits.size(); i++) {
		// goodNumbers.insert(goodNumbers.begin(), quinaryDigits[i] * 2);
		cout << quinaryDigits[i] * 2;
	}

	cout << endl;
	return 0;


}


