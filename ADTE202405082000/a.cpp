#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	if (s[0] != '<') {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '>') {
			if (i == s.size() - 1) {
				cout << "Yes" << endl;
				return 0;
			} else {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}