#include <iostream>
#include <string>

using namespace std;

bool isExtendedABC(const string& s) {
	char currentChar = s[0];

	for (char c: s) {
		if (c != currentChar) {
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