// Copied the following solution:
// https://atcoder.jp/contests/abc353/editorial/9958
#include <cctype> // islower, isupper, tolower, toupper
#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;

	int lower=0, upper=0;
	for (auto& c: S) {
		(islower(c)? lower:upper) ++;
	}

	if (lower < upper) {
		for (auto& c: S) {
			if (islower(c)) c = toupper(c);
		}
	} else {
		for (auto& c: S) {
			if (isupper(c)) c = tolower(c);
		}
	}

	cout << S << '\n';
}