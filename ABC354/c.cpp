#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	// vector<int> a(n);
	// vector<int> c(n);
	vector<vector<int>> p(n);

	for (int i=0; i<n; i++) {
		// cin >> a[i] >> c[i];
		p[i][0] = i; // original index
		cin >> p[i][1] >> p[i][2];
	}

	sort(p.begin(), p.end(), [](vector<int> p1, vector<int> p2) {
		return p1[1] < p2[1]; // sort by "Tsuyosa" (Japanese: 強さ)
	});

	for (int i=0; i<n; i++) {
		if (i >= (int)p.size()) {break;}
		for (int j=i+1; j<n; j++) {
			if (j >= (int)p.size()) {break;}
			// since i < j，p[i].first < p[j].first
			if (p[i][2] > p[j][2]) {
				p.erase(p.begin()+i); // erase takes `pointer to the element` as argument
			}
		}
	}

	sort(p.begin(), p.end(), [](vector<int> p1, vector<int> p2) {
		return p1[0] < p2[0];
	});

	cout << p.size() << endl;
	for (int i = 0; i < (int)p.size(); i++) {
		cout << p[i][0]+1;
		if (i!=(int)p.size()-1) cout << " ";
	}
	cout << endl;

	return 0;
}