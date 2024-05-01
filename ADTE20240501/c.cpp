#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int count_same_with_pos = 0;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (B[i] == A[i]) {
			count_same_with_pos++;
		}
	}

	cout << count_same_with_pos << endl;

	return 0;
}