#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto&v: a) cin >> v;
	sort(a.begin(), a.end()); // e.g., 2 3 1 -> 1 2 3

	// //// debug
	// for (auto&v: a) cout << v << " "; 
	// cout << endl;
	// ////

	int r = n;
	ll cnt = 0, res = 0;
	// Shakutori-method (not understood completely)
	for (int i = 0; i < n; i++) { // pair (i, j): r represents j
		r = max(r, i+1); // this means i < j = r
		// Reduce r to untill the smallest index such that a[r-1] + a[i] < 100000000
		while(r-1 > i and a[r-1] + a[i] >= 100000000) {
			r--;
		}
		cnt += n - r;
	}
	for (int i = 0; i < n; i++) res += ll(a[i]) * (n-1); // since a[i] appears in n-1 pairs
	res -= cnt * 100000000; // remove the 100000000 which is removed by taking modulo
	cout << res << endl;
}