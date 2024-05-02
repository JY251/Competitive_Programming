#include <iostream>
#include <vector>
// #include <climits> // LONG_MAX
#include <limits>

using namespace std;

int main() {
	vector<int> a(64);

	for (int i = 0; i < 64; i++) {
		cin >> a[i];
	}

	int power = 1;

	// x_m x_l
	long x_m = 0;
	long x_l = 0;

	// cout << numeric_limits<long>::max() << endl;

	for (int i = 0; i < 32; i++) {
		// if (i == 31) {
		// 	if (numeric_limits<long>::max() - x_l < (long)(power * a[i])) {
		// 		x_m += 1;
		// 		x_l = numeric_limits<long>::max() - x_l;
		// 	}
		// }
		x_l += (long)power * (long)a[i];
		power *= 2;
	}

	for (int i = 32; i < 64; i++) {
		x_m += (long)power * (long)a[i];
		power *= 2;
	}

	if (x_m == 0) {
		cout << x_l << endl;
	} else {
		cout << x_m << x_l << endl;
	}




	return 0;
}