// copied the following solution:
// https://atcoder.jp/contests/adt_hard_20240604_3/editorial/9886
#include <bits/stdc++.h>
using namespace std;

// <IMP> No need to use pow() function because 2*n + 2*n = 2*(n+1) => Only need to store the exponent, but not the value itself
// (Also reduce the time complexity)
// <IMP> I did not come up with this idea. (Or though come up, I did not adopted it)
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