#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N); // A[i] = j means the previous of person i+1 is person j (i: 0-indexed; A[i]: 1-indexed)
	vector<int> next_person(N+1, 0); // reverse_order[i] = j means that A[j] = i, i.e., the next of person 

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		if (A[i] != -1) {
			next_person[A[i]] = i+1;
		} else {
			next_person[0] = i+1;
		}
	}

	vector<int> order(N, 0);

	for (int i = 0; i < N; ++i) {
		if (A[i] == -1) {
			order[0] = i + 1;
			break;
		}
	}

	for (int j = 1; j < N; ++j) {
		order[j] = next_person[order[j-1]];
	}

	for (int i = 0; i < N; ++i) {
		cout << order[i] << " ";
	}
	cout << endl;
	return 0;
}