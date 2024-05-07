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

	int ans = 0;
	for (int i = 0; i < 24; i++) {
		for (int k = 0; k <= 9; k++) {
			int j = i + 9;
			int attendees = 0;
			for (auto& office: w_x) {
				if (office.second >= i && office.second <= j) {
					attendees += office.first;
				}
			}
			ans = max(ans, attendees);
		}
	}

	cout << ans << endl;
	return 0;
}