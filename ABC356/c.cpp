#include <bits/stdc++.h>
using namespace std;

// create the vecotr of all the combinations of n C k
vector<vector<int>> all_combinations(int n, int k) {
	vector<vector<int>> res(0);

	// assert k >= 1
	assert(k >= 1);
	// assert n >= k -> Since k>=1, n>=1
	assert(n >= k);

	// n C k = (n-1) C (k-1) + (n-1) C k (if n >= 1 and k >= 1)
	// case n = 1: if n=1, since n>=k, k=1 follows, so no recursion is needed
	// case k = 1:
	if (k == 1) {
		for (int i=0; i<n; i++) {
			vector<int> comb(1, i+1);
			res.push_back(comb);
		}
	}
	//// recursive case
	else {
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
	}
	return res;
}

//// if b is included in a
bool is_included(vector<int> a, vector<int> b) {
	// for all items in b
	for (int i=0; i<(int)b.size(); i++) {
		bool is_element_included = false;
		// for all items in a
		for (int j=0; j<(int)a.size(); j++) {
			if (b[i] == a[j]) {
				is_element_included = true;
				break; // break (the for loop of a)
			} else {
				continue; // continue to check if b is the same as the next element in a
			}
		}
		if (is_element_included == false) {
			return false; // if one element in b is not included in a, then return false (since b is not included in a)
		} else {
			continue; // continue to check if the next element in b is included in a
		}
	}
	return true;
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
	vector<vector<int>> combs = all_combinations(n, k);
	// for loop for all the possible combinations: n C k
	for (auto& comb: combs) {
		bool is_valid = true; // if contradiction with the test cases is found, then is_valid = false
		// for loop for all the test cases
		for (int i=1; i<=m; i++) {
			// if the combination of k keys is included in the test case: if comb is included in a[i]
			if (is_included(a[i], comb)) {
				// OPT: if the case is completely the same as the combination: i.e., the len of a[i] == len of comb
				if (a[i].size() == comb.size()) {
					if (r[i] == 'o') {
						// the test case is OK
						continue; // continue to the next test case (No contradiction is found with current test case)
					} else {
						// the combination is confirmed that not working => break the for loop of combinations
						is_valid = false;
						// break the for loop of test cases (Since one contradiction is found, no need to check the rest of the test cases)
						// since the combination is found not working
						break; 
					}
				} else {
					// if not the same (i.e., test case is longer than the combination, we can't confirm is the combination is working or not 
						// for both the test case is `o` and `x` (TMP)					
					continue; // No info is obtained; continue to the next test case					
				}
			}
		}
		if (is_valid) { // if no contradiction is found with all the test cases
			count++;
		}
	}
	cout << count << endl;

	return 0;
}