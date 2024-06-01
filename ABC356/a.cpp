#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l, r;
	cin >> n >> l >> r;


	for (int i=1; i<=n; i++) { // 1-indexed (so does l, r)
		if (i < l || r < i) {
			cout << i;
		} else {
			// l l+1 ... r-1 r => r, r-1, ... l+1, l
			cout << r - (i - l);
		}


		if (i == n) {
			cout << endl;
		} else {
		cout << " ";
		}
	}

	return 0;
}