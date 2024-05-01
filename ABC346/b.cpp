#include <iostream>
#include <string>

using namespace std;

int main() {
	int W, B;
	cin >> W >> B;

	string S = "wbwbwwbwbwbw";
	int n = S.size();

	for (int len = 1; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) {
			int w_count = 0, b_count = 0;
			for (int j = i; j < i + W + B; j++) {
				if (S[(j%n)] == 'w') {
					w_count++;
				} else {
					b_count++;
				}
			}
			// cout << "w_count: " << w_count << " b_count: " << b_count << endl; // "w_count: 0 b_count: 12
			if (w_count == W && b_count == B) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}