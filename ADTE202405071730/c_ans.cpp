#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	// since there are only 24 patterns in `x` (time zone), we don't need to use vector with size `n`
	vector<int> cnt(24);
	for (int i = 0; i < n; i++) {
		int w, x;
		cin >> w >> x;
		cnt[x] += w;
	}
	int ans = 0;
	// i is the start time
	// 9 <= (i + x) mod 24 < 18
	// i + x is the start time in the time zone of x
	// Point: convert the inequality to the form ... < x < ..., which means you try to solve what kinds of "x satisfy" the inequality
	// 9 - i mod 24 <= x < 18 - i mod 24
	// sum = cnt[9-i mod 24] + cnt[10-i mod 24] + ... + cnt[17-i mod 24]
	// this is equal to cnt[i]
	// 9-i mod 24 moves from 9, 8, ..., 0, 23, 22, ..., 10
	// by changing the order: 0, 1, 2, ..., 9, 10, ..., 23 it is the same
	// cnt[9-i mod 24] + cnt[10-i mod 24] + ... + cnt[17-i mod 24] = cnt[i] means cnt[9-i mod 24] + cnt[(9-i)+1 mod 24] + ... + cnt[(9-i)+8 mod 24], thus you can calculate the following:
	// cnt[i mod 24] + cnt[(i+1) mod 24] + ... + cnt[(i+8) mod 24] 
	for (int i = 0; i < 24; i++) {
		int sum = 0;
		for (int j = 0; j < 8; j++) {
			sum += cnt[(i+j)%24];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}