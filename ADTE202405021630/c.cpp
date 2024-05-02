#include <iostream>
#include <vector>

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

	for (int i = 0; i < 32; i++) {
		x_l += (long)power * (long)a[i];
		power *= 2;
	}

	for (int i = 32; i < 64; i++) {
		x_m += (long)power * (long)a[i];
		power *= 2;
	}

	if (x_m = 0) {
		cout << x_l << endl;
	} else {
		cout << x_m << x_l << endl;
	}




	return 0;
}