#include <iostream>
#include <vector>

using namespace std;

// AC 5/22 (others: TLE)
int main() {
	int n; // 2^32 = 10^9.6; 2^31 = 10^9.3
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	long sum = 0;
	for (int i = 0; i < n; i++) {
		// remainder is 10^8 at most
		// 2*remainder is 10^8.3 at most, so int is OK
		int remainder = a[i] % 100000000;
		sum += (long)2*remainder;
	}

	cout << sum << endl;


}