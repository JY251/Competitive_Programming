#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	unordered_map<char, int> count;
	for (int i=0; i<(int)s.size(); i++) {
		count[s[i]]++;
	}

	unordered_map<int, int> freq;
	for (int i=0; i<(int)count.size(); i++) {
		freq[count[i]]++;
	}

	for (int i=0; i<(int)freq.size(); i++) {
		if (freq[i] != 0 and freq[i] != 2) {
			cout << "No" << endl;
			return 0;
		}
	}
	return 0;
}