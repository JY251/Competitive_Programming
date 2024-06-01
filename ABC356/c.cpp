#include <bits/stdc++.h>
using namespace std;

// create the vecotr of all the combinations of n C k
vector<vector<int>> all_combinations(int n, int k) {
	vector<vector<int>> res(0);

	// assert k >= 1
	// assert n >= k -> Since k>=1, n>=1

	// n C k = (n-1) C (k-1) + (n-1) C k (if n >= 1 and k >= 1)
	// case n = 1: if n=1, since n>=k, k=1 follows, so no recursion is needed
	// case k = 1:
		for (int i=0; i<n; i++) {
			vector<int> comb(1, i+1);
			res.push_back(comb);
		}
	//// recursive case
	// (n-1) C (k-1)
	vector<vector<int>> combs1 = all_combinations(n-1, k-1);
	for (auto& comb: combs1) {
		comb.push_back(n);
		res.push_back(comb);
	}

	// (n-1) C k
	vector<vector<int>> combs2 = all_combinations(n-1, k);
	for (auto& comb: combs2) {
		res.push_back(comb);
	}
	return res;
}

int is_included(vector<int> a, vector<int> b) {

}

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


	int count = 0;
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