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
			int j = i + 1;
			int attendees = 0;
			for (auto& office: w_x) {
				// [office.second + 9, office.second + 18]
				// office.second + 9 < i < i+l < office.second + 18
				if ((office.second + 9)%24 <= i && j <= (office.second + 18)%24) {
					attendees += office.first;
				}
			ans = max(ans, attendees);
		}
	}

	cout << ans << endl;
	return 0;
}