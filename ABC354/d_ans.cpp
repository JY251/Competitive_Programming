// Copy source code from https://atcoder.jp/contests/abc354/editorial/10004
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int mass[2][4] = {
	{2, 1, 0, 1},
	{1, 2, 1, 0}
};

constexpr i64 inf = 4000000000ll;

int main() {
	i64 a, b, c, d;
	cin >> a >> b >> c >> d;

	i64 ans = 0;
	// I have not come up with this idea
	// I have considered for loop for each grid point (though tried to decrease the number of points, but still O(b-d)?
	// Idea: consider how many number of each 1x1 square pieces (there are only 8 types of 1x1 square pieces)
	for (int fy = 0; fy < 2; fy++) {
		for (int fx = 0; fx < 4; fx++) {
			// Q. What is + 3 + inf?: Some Op to avoid overflow?
			const i64 x1 = (a - fx + 3 + inf) / 4, x2 = (c - fx + 3 + inf) / 4;
			const i64 count_x = x2 - x1;
			const i64 y1 = (b - fy + 1 + inf) / 2, y2 = (d - fy + 1 + inf) / 2;
			const i64 count_y = y2 - y1;
			ans += count_x * count_y * mass[fy][fx];
		}
	}

	cout << ans << endl;
}