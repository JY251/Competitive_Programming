#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isAirportCode(string s, string t) {
	// check if t is a length 3 substring of s
	int j = 0;
	cout << "s: " << s << " t: " << t << endl;
	for (int i = 0; i < 3; i++) {
		cout << "i: " << i << endl;
		if (isupper(t[i])) {
			// continue; 
			// continue will skip the rest of the loop and go to the next iteration
			// thus, this continue should be removed
		} else {
			// cout << "Not upper case\n" << endl;
			return false;
		}
		cout << "i (2): " << i << endl;
		for (; j < s.size(); j++) {
			if (t[i] == s[j]  + 'A' - 'a' ) {
				cout << "i: " << i << " j: " << j << endl;
				if (i == 2) {
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
	bool isTrue = isAirportCode(s, t);
	
	if (isTrue) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}