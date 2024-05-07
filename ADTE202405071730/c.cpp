#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> w_x(N);

	for (int i = 0; i < N; i++) {
		cin >> w_x[i].first >> w_x[i].second;
	}

	sort(w_x.begin(), w_x.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	});

	int ans = 0, cnt = 0;
	for (const auto& p: w_x) {
		int w = p.first, x = p.second;
		if (x <= 9) {
			cnt += w;
		} else if (x < 18) {
			ans = max(ans, cnt);
			cnt = w;
		} else {
			ans = max(ans, cnt);
		}
	}

	cout << ans << endl;
	return 0;
}