#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	// A(N) is 0-indexed
	for (int i=0; i<N; i++) {
		cin >> A[i];
	}
	// A[i] (1-idx) => A[i-1] in code

	// P(N) is 0-indexed
	vector<int> P(N);
	// P: 2, ..., N : N-1個
	for (int i=0; i<N-1; i++) {
		cin >> P[i];
	}
	// P[i] (1-idx) => P[i-1] in code

	// debug
	// cout << "A ";
	// for (int i=0; i<N; i++) {
	// 	cout << A[i] << " ";
	// }
	// cout << endl;
	for (int j=0; j<1e100; )

	for (int i=0; i<N-1; i++) {
		A[P[i]-1] = A[P[i]-1] + A[i+1];
		// cout << "loop " << i << ": " << "P_i: " << P[i] << " A[P_i]: " << A[P[i] - 1] << endl;
		// cout << A[P[i]-1] << endl;
	}

	const char* result;
	
	result = (A[0] > 0) ? "+" : (A[0] < 0) ? "-" : "0";
	cout << result << endl;
	return 0;
}