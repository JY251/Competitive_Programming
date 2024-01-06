#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<pair<int, int>> dragon(N+1, make_pair(0, 0));

	// vector<int> x(N+1, 0);

	for (int i = 1; i <= N; ++i) {
		// x[i][0] = i;
		dragon[i] = make_pair(i, 0);
	}

	while (Q--) {
		int type;
		cin >> type;

		if (type == 1) {
			char direction;
			cin >> direction;

			if (direction == 'R') {
				dragon[1].first++;
			} else if (direction == 'L') {
				dragon[1].first--;
			} else if (direction == 'U') {
				dragon[1].second++;
			} else if (direction == 'D') {
				dragon[1].second--;
			}

			for (int i = 2; i <= N; ++i) {
				dragon[i].first = dragon[i-1].first;
				dragon[i].second = dragon[i-1].second;
			}
		} else if (type == 2) {
			int p;
			cin >> p;

			cout << dragon[p].first << " " << dragon[p].second << endl;
		}
	}

	return 0;
}