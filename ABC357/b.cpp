#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	// int lower, upper = 0; -> lower is not initialized as 0 here
	int lower = 0;
	int upper = 0;
	string all_lower = s, all_upper = s;
	for (int i=0; i<(int)s.size(); i++) {
		// Not to forget the `=` sign in the following line:
		if ('a' <= s[i] && s[i] <= 'z') {
			all_upper[i] = all_upper[i] - 'a' + 'A';
			lower += 1;
		} else {
			all_lower[i] = all_lower[i] - 'A' + 'a';
			upper += 1;
		}
	}

	if (lower < upper) {
		s = all_upper;
	} else {
		s = all_lower;
	}

	cout << s << endl;
	return 0;
}