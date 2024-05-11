#include <bits/stdc++.h>
#include "atcoder/modint"

using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto&v: a) cin >> v;
	vector<int> d(11);
	for (int i = 0; i < n; i++) {
		// the contribution of a[k] to the answer as the form of 10^(len(a[j])) * a[i] + a[j] where k = j
		// k appears as j for i-1 times in the pairs (i, j)
		// not that not all the pair (i, j) are considered, only the pairs where i < j are considered
		// so, the larger k is, the more contribution since there are more i s.t. i < j = k

		// this counts the number of a[j] with different len(a[j]) -> this information is used to calculate the contribution of a[k] to the answer where k = i
		d[to_string(a[i]).size()]++; // IMP: cvt to string so that you can easily get the size
	}
	mint res = 0;
	vector<mint> p10(11, 1);
	for (int i = 1; i < 11; i++) p10[i] = p10[i-1] * 10; // p10[i] represents 10^i
	for (int i = 0; i < n; i++) {
		// the contribution of a[k] to the answer as the form of 10^(len(a[j])) * a[i] + a[j] where k = j
		// k appears as j for i-1 times in the pairs (i, j)
		res += mint(a[i]) * i;
		d[to_string(a[i]).size()]--;
		for (int j = 1; j < 11; j++) {
			// the contribution of a[k] to the answer as the form of 10^(len(a[j])) * a[i] + a[j] where k = i
			res += p10[j] * a[i] * d[j];
		}
	}
	cout << res.val() << endl;
}