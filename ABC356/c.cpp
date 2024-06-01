#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; // int is OK
	// n: number of keys; m: number of test cases; k: number of keys required to open the door
	cin >> n >> m >> k;

	vector<int> c(m);
	vector<vector<int>> a(m);
	vector<char> r(m);

	for (int i=1; i<=m; i++) { // 1-indexed
		cin >> c[i];
		vector<int> a_row(c[i]);
		for (int j=1; j<= c[i]; j++) {
			cin >> a_row[j-1]; // a_row is 0-indexed
		}
		a[i] = a_row;
		cin >> r[i];
	}


	// count = 0;
	// for loop for all the possible combinations: n C k
		// is_valid = true;
		// for loop for all the test cases
			// if the combination of k keys is included in the test case
				// OPT: if the case is completely the same as the combination, and then the test case is OK
					// count++;
					// break the for loop
				// if test case is `o`, then the test case is OK: 
					// do nothing (continue)
				// if test case is `x`, then the test case is NG: 
					// is_valid = false;
					// break the for loop (of test cases)
		// if (is_valid) 
			// count++; (since no contradiction is found)
	
	cout << count << endl;

	return 0;
}