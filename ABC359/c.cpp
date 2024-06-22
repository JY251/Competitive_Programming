// Sub1:WA (AC: 0/3, 0/49)
#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long s_x;
	unsigned long long s_y;
	unsigned long long t_x;
	unsigned long long t_y;

	cin >> s_x >> s_y >> t_x >> t_y;

	unsigned long long ans = (s_x - s_y / 2) + (t_x - t_y) - 1;
	cout << ans << endl;
	return 0;
}