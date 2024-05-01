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

	for (int i = 0; i < N; ++i) {
		if (A[i] == -1) {
			order[0] = i + 1;
			break;
		}
	}

	for (int j = 1; j < N; ++j) { // loop: in each loop get who is j-th
		for (int i = 0; i < N; ++i) { // check if person i+1 is j-th
			// printf("i: %d, j: %d\n", i, j);
			if (A[i] == order[j-1]) {
				order[j] = i+1;
				break;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << order[i] << " ";
	}

	cout << endl;

	return 0;
}