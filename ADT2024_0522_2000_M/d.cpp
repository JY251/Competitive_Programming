#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	unordered_map<char, int> count;
	for (int i=0; i<(int)s.size(); i++) {
		count[s[i]]++;
	}
	// cout << (int)count.size() << endl;

	// for (int i=0; i<(int)count.size(); i++) {
	// 	cout << count[i] << " ";
	// }
	// cout << endl;

	unordered_map<int, int> freq;
	for (auto i: count) {
		// cout << i.first << " " << i.second << endl; // t 2
		freq[i.second]++;
	}

	// for (int i=0; i<(int)freq.size(); i++) {
	// 	cout << freq[i] << " ";
	// }
	// cout << endl;

	for (int i=0; i<(int)freq.size(); i++) {
		if (freq[i] != 0 and freq[i] != 2) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}