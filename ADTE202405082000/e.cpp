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
			cnt += p.second / 2;
		}
	}
	return 0;
}