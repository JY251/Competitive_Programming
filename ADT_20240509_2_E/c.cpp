#include <iostream>

using namespace std;

int main() {
	unsigned long a, b, c, d, e, f; // \leq 10e18
	cin >> a >> b >> c >> d >> e >> f;

	// long ans = (a * b * c) - (d * e * f);

	int a_new, b_new, c_new, d_new, e_new, f_new;

	int div = 998244353;
	a_new = (int)(a%(unsigned long)div);
	b_new = (int)(b%(unsigned long)div);
	c_new = (int)(c%(unsigned long)div);
	d_new = (int)(d%(unsigned long)div);
	e_new = (int)(e%(unsigned long)div);
	f_new = (int)(f%(unsigned long)div);

	int ans = (a_new*b_new*c_new) - (d_new*e_new*f_new);

	cout << ans << endl;

	return 0;
}