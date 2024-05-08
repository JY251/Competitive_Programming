#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			// for each pair of i and j
			int is_ok = 1;
			for (int k = 0; k < m; k++) {
				// for each position k
				// if (s[i][k] == 'o' || s[j][k] == 'o') {
				if (s[i][k] == 'x' && s[j][k] == 'x') {
					is_ok = 0;
					break;
				}
			}
			if (is_ok) {
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}