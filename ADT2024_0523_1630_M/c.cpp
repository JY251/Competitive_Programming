#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> s(n);
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}

	for (int i=0; i<n-9; i++) {
		for (int j=0; j<m-9; j++) {
			// start idx of takcode is (i, j)
			int is_takcode = true;
			for (int x=i; x<i+9; i++) {
				for (int y=j; y<j+9; j++) {
					if (x < 3 and y < 3) {
						// Left top and right bottom are all #
						if (s[y][x] != '#') {
							is_takcode = false;
							continue;
						}
					}
					if (x >= 6 and y >= 6) {
						// Right top and left bottom are all #
						if (s[y][x] != '#') {
							is_takcode = false;
							continue;
						}
					}

					if (x == 3 and y <= 3) {
						if (s[y][x] != '.') {
							is_takcode = false;
							continue;
						}
					}

					if (y == 3 and x <= 3) {
						if (s[y][x] != '.') {
							is_takcode = false;
							continue;
						}
					}

					if (x == 5 and y >= 5) {
						if (s[y][x] != '.') {
							is_takcode = false;
							continue;
						}
					}

					if (y == 5 and x >= 5) {
						if (s[y][x] != '.') {
							is_takcode = false;
							continue;
						}
					}
				}
				if (is_takcode == false) continue;
			}
			if (is_takcode) {
				cout << i << " " << j << endl;
			}
		}
	}

	return 0;
}