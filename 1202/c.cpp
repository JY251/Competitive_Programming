#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=0; i<N; i++) {
		int sum = 0;

		for (int j=0; j<N; j++) {
			if (A[j] > A[i]) {
				sum += A[j];
			}
		}

		cout << sum << " ";
	}

	cout << endl;
	return 0;
}