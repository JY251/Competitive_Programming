#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	// A, B => 'A' - 'B' = 1
	// E, A => 'A' - 'E' = (65 - 69) = 4
	// A, E => 'E' - 'A' = 69 - 65 = 4 <= same with 1
	// B, E => 'E' - 'B' = 69 - 66 = 3
	// E, B => 'B' - 'E' = 66 - 69 = -3
	// A, D => 'D' - 'A' = 68 - 65 = 3
	// A, C => 'C' - 'A' = 67 - 65 = 2 <= same with 3
	int s_len = abs(s[0] - s[1]);
	int t_len = abs(t[0] - t[1]);

	if (s_len > 2) s_len = 5 - s_len;
	if (t_len > 2) t_len = 5 - t_len;

	if (s_len == t_len) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}