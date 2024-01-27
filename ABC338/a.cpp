#include <iostream>
#include <string>

using namespace std;

bool isValidString(const string& str) {
	if (str.empty()) {
		return false;
	}

	if (!isupper(str[0])) {
		return false;
	}
	
	for (size_t i = 1; i < str.size(); i++) {
		if (!islower(str[i])) {
			return false;
		}
	}

	return true;
}

int main() {
	string S;
	cin >> S;

	if (isValidString(S)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
