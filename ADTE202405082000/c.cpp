#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> c(n);
	vector<string> d(m+1); // use same index as p
	vector<int> p(m+1);

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> d[i+1];
	}
	for (int i = 0; i < m+1; i++) {
		cin >> p[i];
	}

	// C: what takahashi has eaten
	// D[i] - P[i]: color D[i] takes P[i] JPY

	int total = 0;
	for (int i = 0; i < n; i++) {
		int is_found = 0;
		for (int j = 1; j < m+1; j++) {
			if (d[j] == c[i]) {
				total += p[j];
				is_found = 1;
				break;
			}
		}
		if (is_found == 0) {
			total += p[0];
		}
	}
	cout << total << endl;
	return 0;
}