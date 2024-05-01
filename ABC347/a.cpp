#include <iostream>
#include <vector>
// #include <string>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (A[i] % K == 0) {
			cout << A[i] / K << " ";
		}
	}
	cout << endl;

	return 0;
}