#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> s(n);
	vector<int> c(n);

	int t = 0;

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> c[i];
		// int s;
		// cin >> s;
		t += c[i];
	}

	int winner = t % n;

	// sort
	sort(s.begin(), s.end(), [](const string &a, const string &b) {
		return lexicographical_compare(
			a.begin(), a.end(), b.begin(), b.end(), 
			[](char a, char b) {
				return tolower(a) < tolower(b);
			});
	});

	cout << s[winner] << endl;
	return 0;
}