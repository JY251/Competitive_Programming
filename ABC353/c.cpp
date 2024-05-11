#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; // 2^32 = 10^9.6; 2^31 = 10^9.3
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 1; i < n; i++) {
		// int i_sum = 0
		for (int j = i+1; j < n+1; j++) {
			// i, j is 1-indexed above, but A is 0-indexed.
			// A_1 (1-indexed) = A_0 (0-indexed)
			sum += (a[i-1] + a[j-1]) % 100000000;
		}
	}

	cout << sum << endl;

	// cout << (int)2147483647 << endl; // OK
	// cout << (int)2147483648 << endl; // overflow (0)
	// cout << (int)(2147483647+2147483647) << endl; // overflow: -2
	// cout << (int)4294967295 << endl; // overflow: -1

}