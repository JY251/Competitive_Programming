#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> A(h), B(h);
	for (auto& x: A) cin >> x;
	for (auto& x: B) cin >> x;
	for (int s = 0; s < h; s++) {
		for (int t = 0; t < w; t++) {
			int ok = 1;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (A[(i - s + h)%h][(j-t+w)%w]!=B[i][j]) ok = 0;
				}
			}
			if (ok) {
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
}