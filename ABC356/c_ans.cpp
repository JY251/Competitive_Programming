// Copied the following solution:
// https://atcoder.jp/contests/abc356/editorial/10125
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> ks(m, 0);
	vector<int> r(m, 0);
	for (int i=0; i<m; i++) {
		int c;
		cin >> c;
		for (int j=0; j<c; j++) {
			int a;
			cin >> a;
			a--; // if a is 1, no need to shift and just take `|` (or)
			ks[i] |= (1<<a);
		}
		string s;
		cin >> s;
		if (s=="o"){r[i]=1;}
		else(r[i]=0);
	}

	int res=0;
	// Why 1<<n? - `i` means each combination of keys
	//  `(1<<n) - 1` means 111...11 (n bits), therefore all combinations of keys are included in the following for loop
	// <IMP> I have not come up with this idea of bitwise operation to represent all combinations of keys
	for (int i=0; i<(1<<n); i++) { // for loop for all possible combinations?
		bool jud=true;
		for (int j=0; j<m; j++) { // for loop for each test
			// __builtin_popcount: count the number of 1s in the binary representation of i&ks[j]
			// &: bitwise AND
			// i&ks[j]: the combination of keys that are used in the test case (among the current combination of keys)
			// <IMP> I have checked if each test case includes the combination by for loop, but you can use bitwise operation (I have not come up with this idea of bitwise operation)
			int ok=__builtin_popcount(i&ks[j]);
			// Q. What is the reason if the following condition is satisfied, the combination `i` is not valid? 
			// if the number of used keys is larger than k (answer) and the test case is not passed, it means that the combination is not valid
			if (ok>=k && r[j]==0) {jud=false; break;} // break the for loop of test case
			// if the number of used keys is smaller than k (answer) and the test case is passed, it means that the situation contradicts the problem setting: k keys are needed to pass the test
			if (ok<k && r[j]==1) {jud=false; break;} // break the for loop of test case
		}
		if (jud){res++;}
	}
	cout << res << endl;
	return 0;
}