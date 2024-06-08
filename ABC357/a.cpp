#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> h(n);
	for (int i=0; i<n; i++) {
		cin >> h[i];
	}

	int count = 0;
	int i = 0;
	while(m>0) {
		m-=h[i];
		i++;
		count++;
		if (i == n) {
			break;
		}
	}
	// if m is negative: the last man can't sanitize => count--
	if (m<0) {
		count--;
	}
	cout << count << endl;
	return 0;
}