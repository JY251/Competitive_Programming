#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isGoodString(string s) {
	unordered_map<char, int> charCount;
	for (char c: s) {
		charCount[c]++;
	}

	vector<int> i_counts(s.size(), 0);

	for (auto it: charCount) {
		i_counts[it.second]++;
	}

	for (int i_count: i_counts) {
		if (i_count != 2 && i_count != 0) {
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