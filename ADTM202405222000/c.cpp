#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	// A, B => 'A' - 'B' = 1
	// E, A => 'A' - 'E' = (65 - 69) = 4
	// A, E => 'E' - 'A' = 69 - 65 = 4
	int s_len = abs(s[0] - s[1]);
	int t_len = abs(t[0] - t[1]);

	if (s_len == t_len) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}