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
		i_counts[it.second - 1]++; 
		// if here is [it.second], then string such as "aaa" will be considered as good string
		// because it.second = 3, and i_counts[3] will be 1, but in the next for loop, loop moves from 0 to 2, so i_counts[3] will not be checked
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