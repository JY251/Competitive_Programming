// https://atcoder.jp/contests/adt_hard_20240604_3/tasks/abc351_c
#include <bits/stdc++.h>
using namespace std;

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
		// push_back the ball of 2**a[i] to the list (rightmost)
		// deque.push_front(2**a[i])

		// if list.size() > 1
			// if (list[0] == list[1])
				// continue (go to next loop)
			// else
				// new_element
				// new_element = pop_front()
				// new_element += pop_front()
				// push_front(new_element)
		// else
			// continue (go to next loop)

		cout << list.size() << endl;
	return 0;
}