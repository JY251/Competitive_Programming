#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}

	return 0;
}