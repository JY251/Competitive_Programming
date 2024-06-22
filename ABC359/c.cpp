// Sub3:WA (AC: 2/3, 13/49)
#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long s_x;
	unsigned long long s_y;
	unsigned long long t_x;
	unsigned long long t_y;

	cin >> s_x >> s_y >> t_x >> t_y;

	unsigned long long delta_x = s_x > t_x ? s_x - t_x : t_x - s_x;
	unsigned long long delta_y = s_y > t_y ? s_y - t_y : t_y - s_y;

	// NOTE: abs is not supported for unsigned long long
	unsigned long long ans = (delta_x / 2) + (delta_y ? delta_y -1: 0);
	cout << ans << endl;
	return 0;
}