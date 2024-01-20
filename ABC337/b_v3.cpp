#include <iostream>
#include <string>

using namespace std;

bool isExtendedABC(const string& s) {
	if (s.empty()) {
		return true;
	}

	// char firstChar = s[0];
	// char secondChar = 0;
	// char thirdChar = 0;
	
	// if (firstChar != 'A') {
	// 	return false;
	// }

	for (char c : s) {
		if (c != 'A') {
			if (c == 'B') {
				break;
			} else {
				cout << "not char A and B" << endl;
				return false;
			}
		} else {
			continue;
		}
	}

	for (char c : s) {
		if (c != 'B') {
			if (c == 'C') {
				break;
			} else {
				cout << "not char B and C - " << "char: " << c << " " << endl;
				return false;
			}
		}
	}

	for (char c : s) {
		if (c != 'C') {
			if (c == '\0') {
				return true;
			}
			cout << "not char C" << endl;
			return false;
		}
	}

	return true;
}

int main() {
	string s;
	cin >> s;

	bool result = isExtendedABC(s);

	if (result) {
		cout << "Yes" << endl;
	}	else {
		cout << "No"  << endl;
	}

	return 0;
}