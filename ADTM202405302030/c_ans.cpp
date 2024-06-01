// Copied the following solution:
// https://atcoder.jp/contests/adt_medium_20240530_3/editorial/3744
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, k;
	cin >> a >> b >> k;

	int res = 0;
	while (a<b) {
		a *= k;
		res++;
	}
	cout << res << endl;
}