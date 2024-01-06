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

	for (int i = 1; i <= N; ++i) {
		cout << "(" << dragon[i].first << " " << dragon[i].second << ")";
	}
	cout << endl;
	int tmp_x, tmp_y;

	while (Q--) {
		int type;
		cin >> type;

		int tmp_x[2], tmp_y[2];

		if (type == 1) {
			char direction;
			cin >> direction;

			for (int i = 1; i <= N; ++i) {
				int idx = i % 2;
				int idx2 = (i+1) % 2;
				tmp_x[idx] = dragon[i].first;
				tmp_y[idx] = dragon[i].second;

				if (i==1) {
					if (direction == 'R') {
						dragon[1].first++;
					} else if (direction == 'L') {
						dragon[1].first--;
					} else if (direction == 'U') {
						dragon[1].second++;
					} else if (direction == 'D') {
						dragon[1].second--;
					}
					continue;
				}
				dragon[i].first = tmp_x[idx2];
				dragon[i].second = tmp_y[idx2];
			}

			for (int i = 1; i <= N; ++i) {
				cout << "(" << dragon[i].first << " " << dragon[i].second << ")";
			}
			cout << endl;
		} else if (type == 2) {
			int p;
			cin >> p;

			cout << dragon[p].first << " " << dragon[p].second << endl;
		}
	}
	// cout << endl;

	return 0;
}