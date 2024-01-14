#include <iostream>
#include <vector>
using namespace std;

long maxPyramidSize(long N, const vector<long> &A) {
	long ans;

	if (N == 1) {
		ans = 1;
		return ans;
	}

	if (N % 2 == 0) {
		vector<long> A_without_head(A.begin()+1, A.end());
		vector<long> A_without_tail(A.begin(), A.end()-1);
		long ans1 = maxPyramidSize(N-1, A_without_head);
		long ans2 = maxPyramidSize(N-1, A_without_tail);
		ans = max(ans1, ans2);
		return ans;
		// ans = N-1;
	} else {
		// cout << "N: " << N << endl;

		for (int i=0; i<(N+1)/2; i++) {
			// cout << "A[" << i << "]: " << A[i] << "; i+1: " << i+1 << endl;
			// cout << "A[" << N-i-1 << "]: " << A[N-i-1] << "; i+1: " << i+1 << endl;
			if (A[i] >= i+1 && A[N-i-1] >= i+1) {
				continue;
			} else {
				vector<long> A_without_head(A.begin()+1, A.end());
				vector<long> A_without_tail(A.begin(), A.end()-1);
				long ans1 = maxPyramidSize(N-1, A_without_head);
				long ans2 = maxPyramidSize(N-1, A_without_tail);
				ans = max(ans1, ans2);
				return ans;
			}
		}
		ans = N;
	}

	return ans;

}

int main() {
	long N;
	cin >> N;

	vector<long> A(N);
	for (long i = 0; i < N; i++) {
		cin >> A[i];
	}

	cout << maxPyramidSize(N, A) << endl;

	return 0;
}