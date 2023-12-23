#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long A;
	long long M;
	long long L, R;

	cin >> A >> M >> L >> R;

	// A = 0;
	// M = 1;
	// L = -1e18;
	// R = 1e18;

	// 20_0000_0000_0000_0001
	// 100_0000_0000_0000_0001
	// 200_0000_0000_0000_0001

	if (L == R) {
		if ((A - L)%M == 0) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		// cout << 0 << endl;
		return 0;
	}

	// cout << log10(abs(A)) << " " << log10(abs(L)) << " " << log10(abs(R)) << endl;
	// cout << A-L << " " << R-A << endl;
	// cout << log10(abs(A-L)) << " " << log10(abs(R-A)) << endl;
	long long negative_tree = (A - L) / M;

	long long positive_tree = (R - A) / M;

	// cout << negative_tree << " ";
	// cout << positive_tree;
	// cout << endl;

	long long trees;
	if (A < L) {
		trees = negative_tree + positive_tree;
		if ((A - L) % M == 0) {
			trees++;
		}
	} else if (A > R) {
		trees = negative_tree + positive_tree;
		if ((R - A) % M == 0) {
			trees++;
		}
	} else {
		trees = negative_tree + positive_tree + 1;
	}

	cout << trees << endl;
	return 0;
}

// -177018739841739480 2436426 -80154573737296504 585335723211047198
// 177018739841739480 2436426 -585335723211047198 80154573737296504 