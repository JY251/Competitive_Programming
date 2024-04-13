#include <iostream>
#include <unordered_map>

using namespace std;

bool isGoodString(string s) {
	unordered_map<char, int> charCount;
	for (char c: s) {
		charCount[c]++;
	}

	for (auto it: charCount) {
		if (it.second != 0 && it.second != 2) {
			return false;
		}
	}

	return true;
}

int main() {
	string s;
	cin >> s;

	bool isGood = isGoodString(s);

	if (isGood) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}