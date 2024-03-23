#include <vector>
#include <iostream>

using namespace std;

vector<int> buildPrefixTable(const string& pattern) {
	int n = pattern.size();
	vector<int> P(n, 0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = P[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			P[i] = j + 1;
			j++;
		}
		printf("i: %d, j: %d\n", i, j);
	}
	return P;
};

bool kmpSearch(const string& text, const string& pattern) {
	int n = text.size();
	int m = pattern.size();
	vector<int> P = buildPrefixTable(pattern);
	for (int i = 0; i < m; i++) {
		cout << P[i] << " ";
	}
	cout << endl;
	int i = 0, j = 0;
	while (i < n) {
		cout << i << " " << j << " ";
		if (text[i] == pattern[j]) {
			cout << "O" << endl;
			i++;
			j++;
			if (j == m) {
				return true;
			}
		} else {
			cout << "X" << endl;
			if (j > 0) {
				j = P[j - 1];
			} else {
				i++;
			}
		}
	}

	return false;
}

int main() {
	string text = "abababb";
	string pattern = "ababb";

	kmpSearch(text, pattern);

	return 0;
}