// WA: AC: 3/3, 44/49
// Copied the following solution:
// https://atcoder.jp/contests/abc359/editorial/10264
#include <bits/stdc++.h>
using namespace std;

int main() {
	long Sx, Sy, Tx, Ty;
	cin >> Sx >> Sy >> Tx >> Ty;

	// Start
	if ((Sx + Sy) % 2 == 1) {
		--Sx;
	}
	// if ((Tx + Ty) % 2 == 1) {
	// 	--Tx;
	// }

	long Dx = abs(Sx - Tx);
	long Dy = abs(Sy - Ty);

	cout << (Dy + max(Dx, Dy)) / 2 << endl;
	return 0;
}