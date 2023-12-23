#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long A;
	int M;
	long L, R;

	cin >> A >> M >> L >> R;

	int trees = 0;
	for (int k = L; k <= R; k+=M) {
		if (A + k >= L && A + k <= R) {
			trees++;
		}
	}

	// long long first_tree = ceil((double) L / M) * M;
	// long long last_tree = floor((double) R / M) * M;

	// long long total_trees = (last_tree - first_tree) / M + 1;

	// cout << total_trees << endl;
	cout << trees << endl;
	return 0;
}