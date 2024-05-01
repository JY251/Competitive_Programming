#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int countSubstrings(const string& S) {
	unordered_set<string> substrings;
	int n = S.size();

	for (int i = 0; i < n; ++i) {
		string substring = "";
		for (int j = i; j < n; ++j) {
			substring += S[j];
			substrings.insert(substring);
		}
	}

	return substrings.size();
}

int main() {
	string S;
	cin >> S;

	int result = countSubstrings(S);
	cout << result << endl;
	return 0;
}