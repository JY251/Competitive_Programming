#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char mostFrequentCharacter(const string& str) {
	vector<int> count (26, 0);

	for (char ch: str) {
		count[ch - 'a']++;
	}

	int maxCount = 0;
	char mostFrequentChar = 'a';
	for (int i = 0; i < 26; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			mostFrequentChar = 'a' + i;
		}
	}

	return mostFrequentChar;
}

int main() {
	string S;
	cin >> S;

	char mostFrequentChar = mostFrequentCharacter(S);
	cout << mostFrequentChar << endl;
	return 0;
}