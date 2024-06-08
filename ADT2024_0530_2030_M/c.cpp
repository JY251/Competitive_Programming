// Problem: https://atcoder.jp/contests/adt_medium_20240530_3/tasks/abc248_b
#include <iostream>
// #include <cmath>
using namespace std;

int main() {
	//// NOTE: `int` is OK here since a, b does not over 10**9
	// int: 32 bits: 2^31-1 = 2147483647
	//  log10(2147483647) = 9.33 => int: 10**9.33 is OK
	int a, b, k;
	cin >> a >> b >> k;


	// a * k ** ans = b
	// k ** ans = b / a
	// int ans;
	// ans = clog(b/a)

	//// NOTE:
	// int curr; does not work
	//// 2147483641 2147483642 2 => runtime error if `int` is used
	// actual answer is 1: 2147483641 * 2 = 4294967282
	// However 2147483641 * 2 will overflow (-14) the range of int
	// then -14 * 2 * 2 * 2 ... < 0 occurs and does not reach 4294967282
	// cout << (int)2147483641 * 2 << endl; // overflow
	long curr = a;
	int count = 0;
	while (curr < (long)b) {
		curr *= k;
		count++;
	}
	cout << count << endl;

	return 0;
}