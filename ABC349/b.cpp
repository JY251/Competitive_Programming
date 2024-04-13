#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isGoodString(string s) {
	unordered_map<char, int> charCount;
	for (char c: s) {
		charCount[c]++;
	}

	int remaining = s.size();
	int i = 1;

	vector<bool> visited(s.size(), false);
	while (remaining != 0) {
		for (int j = 0; j < s.size(); j++) {
			if (visited[j]) {
				continue;
			} else {
				if ()
				visited[j] = true;
				remaining
			}
		}
	}

	for (int i = 0; i < s.size(); i++) {

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