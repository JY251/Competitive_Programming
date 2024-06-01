// Problem: https://atcoder.jp/contests/adt_medium_20240530_3/tasks/abc248_b
#include <iostream>
// #include <cmath>
using namespace std;

int main() {
	long a, b, k;
	cin >> a >> b >> k;

	// a * k ** ans = b
	// k ** ans = b / a
	// int ans;
	// ans = clog(b/a)

	long curr = a;
	int count = 0;
	while (curr < b) {
		curr *= k;
		count++;
	}
	cout << count << endl;

	return 0;
}