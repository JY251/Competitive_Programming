#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long sum = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) { // Not to count i twice
			stringstream ss;
			ss << a[i] << a[j]; // this is not str
			// a[i], a[j] is 10^9.3 at most (int), so stoi(ss.str()) is 10^18.6 at most: overflow for int; long (2^63 = 10^18.9) is OK
			// no function like stol?
			// sum += stol(ss.str()) % 998244353;
			sum = (sum + (stol(ss.str()) % 998244353)) % 998244353;
			// sum += (long)998244353-1;
		}
	}

	// worst case: n = 200000, f is 998244353-1 for all the 200000C2 pairs
	// it will be (998244353-1)*200000*190000/2 = 1.8966642688e+19 (over long type?) = 1e19.277, which over long type (1e18.96) or unsigned long (1e19.265)

	cout << sum % 998244353 << endl; // not to forget calc remainder
	cout << sum << endl; // not to forget calc remainder

	// cout << (long)(998244353-1) * 200000 << endl; // no overflow


	return 0;
}