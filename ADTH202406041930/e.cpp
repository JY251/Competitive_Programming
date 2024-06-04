// https://atcoder.jp/contests/adt_hard_20240604_3/tasks/abc351_c
#include <bits/stdc++.h>
using namespace std;

int power2(int n) {
	int res = 1;
	for (int i=0; i<n; i++) {
		res *= 2;
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	// empty list: deque
	// <- right left ->
	// 0 1 ... n-1
	deque<int> list(0);

	// N loop
	for (int i=0; i<n; i++) {
		cout << "Iteration: " << i << " " <<	list.size() << endl; // i=1 means after the 1st iteration
		for (int j=0; j<list.size(); j++) {
			cout << list[j] << " ";
		}
		cout << endl;
		// push_back the ball of 2**a[i] to the list (rightmost)
		// deque.push_front(2**a[i])
		list.push_front(power2(a[i]));

		if (list.size() > 1) {
			if (list[0] != list[1]) {
				continue; // continue (go to next loop)
			} else {
				// new_element
				int new_element = list.front();
				list.pop_front();
				new_element += list.front();
				list.pop_front();
				list.push_front(new_element);
			}
		} else {
			continue; // continue (go to next loop)
		}
	}
	cout << list.size() << endl;
	return 0;
}