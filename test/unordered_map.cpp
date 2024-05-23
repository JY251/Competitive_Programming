#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	unordered_map<char, int> count;
	for (int i=0; i<(int)s.size(); i++) {
		count[s[i]]++;
	}
	cout << count.size() << endl;
	cout << (int)count.size() << endl;
}