#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	// vector<vector<int>> b(n, vector<int>(m));

	for (int i=0; i<m; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			// cin >> b[i][j];
			int taken;
			cin >> taken;
			a[i] -= taken;
		}
	}

	// vector<int> taken_nutrients(m);
	// for

	for (int i=0; i<n; i++) {
		if (a[i] > 0) { // if there are any nutrients not reached the goal
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	return 0;
}