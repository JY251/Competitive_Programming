#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K;
	vector<int> A;

	cin >> N >> K;
	A.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> A[i];
	}

	// sort(A.begin(), A.end());

	// int minStrangeness = 0;
	// int remainingPairs = 2 * N - K;

	// for (int i = 1; i <= remainingPairs; i++) {
	// 	minStrangeness += abs(i - A[(i-1) % K]);
	// }

	// // vector<int> remainingColors;
	// // for (int i = 0; i < N; i++) {
	// // }

	// cout << minStrangeness << endl;
	
	return 0;
}