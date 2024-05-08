#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> find_continuous_T(string& s) {
	int n = s.size();
	vector<pair<int, int>> continuous_T;

	int is_prev_T = 0;
	int previous_continuous_T = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			if (is_prev_T) {
				// previous is T
				previous_continuous_T++;
				// is_prev_T = 1; // unnecessary
			} else {
				// prev is not T
				previous_continuous_T = 1;
				is_prev_T = 1;
			}
		} else {
			if (is_prev_T) {
				// prev is T but this is not T
				continuous_T.push_back({i-previous_continuous_T, previous_continuous_T});
			} else {
				// prev is not T and this is not T
				continue;
			}
		}
	}
	return continuous_T;
}

int main() {
	int h, w;
	cin >> h >> w;

	vector<string> s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	int cnt = 0;

	for (int i = 0; i < h; i++) {
		vector<pair<int, int>> continuous_T = find_continuous_T(s[i]);
		for (auto& p : continuous_T) {
			if (p.second % 2 == 0) {
				// even number of continuous T
				for (int j = 0; j < p.second; j++) {
					if (j % 2 == 0) {
						s[i][j+p.first] = 'P';
					} else {
						s[i][j+p.first] = 'C';
					}
				}
			} else {
				// odd number of continuous T
				for (int j = 0; j < p.second - 1; j++) {
					if (j % 2 == 0) {
						s[i][j+p.first] = 'P';
					} else {
						s[i][j+p.first] = 'C';
					}
				}
			}
		}
	}

	for (int i = 0; i < w; i++) {
		cout << s[i] << endl;
	}
	return 0;
}