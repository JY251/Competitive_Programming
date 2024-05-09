#include <iostream>

using namespace std;

int main() {
	unsigned long a, b, c, d, e, f; // \leq 10e18
	cin >> a >> b >> c >> d >> e >> f;

	// long ans = (a * b * c) - (d * e * f);

	long a_new, b_new, c_new, d_new, e_new, f_new;

	long div = 998244353; // this is within the range of int
	a_new = (a%(unsigned long)div);
	b_new = (b%(unsigned long)div);
	c_new = (c%(unsigned long)div);
	d_new = (d%(unsigned long)div);
	e_new = (e%(unsigned long)div);
	f_new = (f%(unsigned long)div);

	// cout << a_new << " " << b_new << " " << c_new << " " << d_new << " " << e_new << " " << f_new << endl;

	// e.g., 998244352 % 998244353 will be 998244352 (but not -1), so it will cause digit overflow
	// a_new, b_new, ... will be 1 ~ 998244352
	// however, 998244352 * 998244352 will be overflowed of int; long is OK

	// 998244352 * 998244352 * 998244352 will overflow even long => take modulo
	long ans = (((a_new*b_new%div)*c_new%div) - ((d_new*e_new)%div*f_new%div))%div;

	// cout << (long) 998244352 * 998244352 << endl;
	// cout << 998244352 * 998244352 << endl;


	cout << ans << endl;

	return 0;
}