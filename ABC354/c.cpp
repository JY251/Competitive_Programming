#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	// vector<int> a(n);
	// vector<int> c(n);
	vector<pair<int, int>> p(n);

	for (int i=0; i<n; i++) {
		// cin >> a[i] >> c[i];
		cin >> p[i].first >> p[i].second;
	}

	sort(p.begin(), p.end(), [](pair<int, int> p1, pair<int, int> p2) {
		return p1.first < p2.first; // sort by "Tsuyosa" (Japanese: 強さ)
	});

	for (int i=0; i<n; i++) {
		if (i >= p.size()) {break;}
		for (int j=i+1; j<n; j++) {
			if (j >= p.size()) {break;}
			// since i < j，p[i].first < p[j].first
			if (p[i].second > p[j].second) {
				p.erase(i);
			}
		}
	}

	return 0;
}