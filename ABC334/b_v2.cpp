#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long A;
	long M;
	long L, R;

	cin >> A >> M >> L >> R;

	if (L == R) {
		cout << 0 << endl;
		return 0;
	}

	cout << A-L << " " << R-A << endl;
	cout << log10(abs(A-L)) << " " << log10(abs(R-A)) << endl;
	long negative_tree = (A - L) / M;

	long positive_tree = (R - A) / M;

	cout << negative_tree << " ";
	cout << positive_tree;
	cout << endl;

	long trees = negative_tree + positive_tree + 1;

	cout << trees << endl;
	return 0;
}