#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	vector<int> order(N, 0);
	vector<int> position(N+1, 0); // position[i] = j means person i is j-th (i, j is 1-indexed)

	for (int i = 0; i < N; ++i) {
		if (A[i] == -1) {
			order[0] = i + 1;
			position[i+1] = 1; // person i+1 is 1-th
			break;
		}
	}

	for (int j = 1; j < N; ++j) {
		order[j] = position[A[order[j-1]-1]];
		position[A[order[j-1]-1]] = j+1;

		// order[j-1] is previous of j-th (j: 0-indexed)
		// A[order[j-1]]
	}

	for (int i = 0; i < N; ++i) {
		cout << order[i] << " ";
	}
	cout << endl;
	return 0;
}