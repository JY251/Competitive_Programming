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

	unsigned long power = 1;

	// x_m x_l
	unsigned long x_l = 0;

	// cout << numeric_limits<long>::max() << endl;

	for (int i = 0; i < 64; i++) {
		// if (i == 31) {
		// 	if (numeric_limits<long>::max() - x_l < (long)(power * a[i])) {
		// 		x_m += 1;
		// 		x_l = numeric_limits<long>::max() - x_l;
		// 	}
		// }
		x_l += (unsigned long)power * (unsigned long)a[i];
		power *= 2;
		// cout << power << " (" << i << "; x_l)" << endl;
	}

	cout << x_l << endl;

	// cout << "debug: " << "x_m: " << x_m << " x_l: " << x_l << " x_m + x_l: " << x_m + x_l << "\n";



	return 0;
}