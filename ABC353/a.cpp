#include <iostream>
// #include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	// vector<int> v(n);
	// for (int i = 0; i < n; i++) {
	// 	cin >> v[i];
	// }

	int most_left_height;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cin >> most_left_height;
		} else { // not to forget to put the following line in the else block (otherwise, for i = 0, the following will be executed)
			int height;
			cin >> height;
			// cin >> v[i];

			// cout << "most_left_height: " << most_left_height << ", height: " << height << "(i: " << i << ")" << endl;

			if (most_left_height < height) {
				cout << i+1 << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;
	return 0;
}