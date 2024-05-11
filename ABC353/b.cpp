#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int count = 0;
	int current_in = 0;

	for (int i = 0; i < n; i++) {
		if (k - current_in < a[i]) {
			count++;
			// not to make this `current_in = 0`. (Doing so, you did not add a[i] to the current_in.)
			current_in = a[i];
			// cout << "count: " << count << endl;
		} else {
			current_in += a[i];
			// cout << "current_in: " << current_in << endl;
		}
	}
	// not to forget because there are some people in the attraction but start is not executed.
	if (current_in > 0) {
		count++;
	}

	cout << count << endl;
	return 0;
}