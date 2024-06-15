#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a; // 1e6

	cin >> n >> a;

	vector<int> T(n);

	for (int i=0; i<n; i++) {
		cin >> T[i];
	}

	int previous_fin = 0;

	for (int i=0; i<n; i++) {
		// first customer (i=0)
		if (i == 0) {
			previous_fin = T[i] + a;
		} else {
			// 2nd: first fin <= second com: return second com + A
			if (previous_fin <= T[i]) {
				previous_fin = T[i] + a;
			}
			// 2nd: first fin > second com: return first fin + A
			if (previous_fin > T[i])
				previous_fin = previous_fin + a;
		}

		// print i-th
		cout << previous_fin << endl;
	}
	return 0;
}