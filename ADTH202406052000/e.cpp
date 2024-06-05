// https://atcoder.jp/contests/adt_hard_20240605_3/tasks/abc347_c
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	vector<int> d;

	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		cin >> d[i];
	}
	int count = 0;
	// Loop: The case d_1 is the first day of holiday, second day of holiday, ..., A-th day of holiday: i
	for (int i=1; i<=a; i++) {
		bool is_ok = true;
		// loop: d_2, ..., d_n
		for (int j=1; j<n; j++) {
			// check if d_i is holiday
			int diff = d[j] % (a+b) - d[0] % (a+b);
			// NOTE: i=2 (d_1 is the 2nd day of holiday) -> -1 from d_i is also holiday: -1 = 1 - 2
			// NOTE: i=3 (d_1 is the 3rd day of holiday) -> -2, -1 from d_i is also holiday: -2 = 1- 3
			// if 2-5 and d_i = 2, d_2 = 8 -> diff = 8-2 = 6 but 6-7 = -1, which is the first day of holiday
			if (diff > a-i) {
				diff -= (a+b);
			} 
			// if not "(1-i) < diff < (a-i)"
			if (!((1-i) < diff && diff < (a-i))) {
				is_ok = false;
				break; // break the loop of d_2, ..., d_n
			}
		}

		if (is_ok) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}