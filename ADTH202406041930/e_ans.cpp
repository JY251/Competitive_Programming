// copied the following solution:
// https://atcoder.jp/contests/adt_hard_20240604_3/editorial/9886
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,l=0;
	int a[200000]; // max of n is 200000 (ther are atmost n balls in the list)
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[l];
		l++; // l is the last index of the array
		while(l>1) {
			if(a[l-1] == a[l-2]) {
				a[l-2] ++;
				l--;
			}
			else break;
		}
	}
	cout << l << endl;
	return 0;
}