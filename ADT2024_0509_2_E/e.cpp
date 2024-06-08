#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> finds_diagonal_pairs(int n) {
	vector<pair<int, int>> pairs;
	if (n >= 6) {
		pairs.push_back({0, 0});
		for (int i = 0; i < n - 6; i++) {
			pairs.push_back({0, i});
			pairs.push_back({i, 0});
		}
	}
	return pairs;
}

vector<pair<int, int>> finds_diagonal_pairs_lb_rt(int n) {
	vector<pair<int, int>> pairs;
	if (n >= 6) {
		pairs.push_back({n-1, 0});
		for (int i = 0; i < n - 6; i++) {
			pairs.push_back({n-1, i});
			pairs.push_back({n-1-i, 0});
		}
	}
	return pairs;
}

int main() {
	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	char black = '#';
	// char white = '.';

	// if possible in row direction
	for (int i = 0; i < n; i++) {
		// e.g,, if n = 8: [0 1 2 3 4 5], [1 2 3 4 5 6], [2 3 4 5 6 7] are possible => n-6 (n-6 is also OK)
		for (int j = 0; j <= n-6; j++) {
			// cout << "i: " << i << " j: " << j << endl;
			// each candidate for the left end of the 6 continuous black
			int black_count = 0;
			// int white_count = 0;

			// if in the 6 elements, if there are only 2 white, then it is possible
			// if in the 6 elements, if there are at least 4 black, then it is possible
			for (int k = 0; k < 6; k++) {
				// if (s[i][j+k] == white) {
				// 	white_count++;
				// }
				if (s[i][j+k] == black) {
					black_count++;
				}
				if (black_count == 4) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	// if possible in column direction
	for (int i = 0; i < n; i++) {
		// e.g,, if n = 8: [0 1 2 3 4 5], [1 2 3 4 5 6], [2 3 4 5 6 7] are possible => n-6
		for (int j = 0; j <= n-6; j++) {
			// cout << "i: " << i << " j: " << j << endl;
			// each candidate for the left end of the 6 continuous black
			int black_count = 0;
			// int white_count = 0;

			// if in the 6 elements, if there are only 2 white, then it is possible
			// if in the 6 elements, if there are at least 4 black, then it is possible
			for (int k = 0; k < 6; k++) {
				// if (s[i][j+k] == white) {
				// 	white_count++;
				// }
				if (s[j+k][i] == black) {
					black_count++;
				}
				if (black_count == 4) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	// if possible in diagonal (left up to right down) direction
	for (auto& pair: finds_diagonal_pairs(n)) {
		int j_max = -1;
		if (pair.first == 0) {
			if (pair.second == 0) j_max = n - 6;
			else j_max = n - 6 - pair.second;
		} else if (pair.second == 0) {
			j_max = n - 6 - pair.first;
		} else {
			// error
			cerr << "error" << endl;
			return -1;
		}
		for (int j = 0; j <= j_max; j++) {
			int black_count = 0;

			for (int k = 0; k < 6; k++) {
				if (s[pair.first+j+k][pair.second+j+k] == black) {
					black_count++;
				}
				if (black_count == 4) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	// if possible in diagonal (left down to right up) direction
	for (auto& pair: finds_diagonal_pairs_lb_rt(n)) {
		int j_max = -1;
		if (pair.first == n-1) {
			if (pair.second == 0) j_max = n - 6;
			else j_max = n - 6 - pair.second;
		} else if (pair.second == 0) {
			j_max = n - 6 - (n-1 - pair.first);
		} else {
			// error
			cerr << "error" << endl;
			return -1;
		}
		for (int j = 0; j <= j_max; j++) {
			int black_count = 0;

			for (int k = 0; k < 6; k++) {
				if (s[pair.first-j-k][pair.second+j+k] == black) {
					black_count++;
				}
				if (black_count == 4) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}

	cout << "No" << endl;

	return 0;
}