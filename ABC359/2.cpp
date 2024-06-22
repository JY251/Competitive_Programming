// Sub1: WA (AC 1/3, 5/13)
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> a(2*n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	int count = 0;

	// n-1: the last person; n-2: the second last person; n-3: the third last person
	for (int i=0; i<n-2; i++) {
		if (a[i] == a[i+2]) {
			count ++;
		}
	}
	cout << count << endl;

	return 0;
}