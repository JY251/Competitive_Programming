#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAirportCode(string s, string t, int n) {
	// check if t is a length 3 substring of s
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (isupper(t[i])) {
		} else {
			return false;
		}
		for (; j < s.size(); j++) {
			if (t[i] == s[j]  + 'A' - 'a' ) {
				if (i == n-1) {
					return true;
				}
				break;
			}
		}
	}
	return false;
}

int main() {
	string s, t;
	cin >> s >> t;

	bool isTrue;
	if (t.size() != 3) {
		isTrue = false;
	} else {
	bool isTrue3 = isAirportCode(s, t, 3);
	bool isTrue2 = isAirportCode(s, t, 2) && t[2] == 'X';
	// bool isTrue2 = isAirportCode(s, t, 2);
	isTrue = isTrue3 || isTrue2;
	}

	
	if (isTrue) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}