#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::int128_t;

vector<__int128> cumulative_sum(const vector<int> &A) {
	vector<__int128> S(A.size() + 1, 0);
	S[0] = 0;
	for (int i = 1; i <= A.size(); i++) {
		S[i] = S[i - 1] + A[i-1];
	}
	return S;
}

int main() {
	int N, C;
	cin >> N >> C;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector <__int128> S = cumulative_sum(A);

	vector <__int128> dp(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int l = 1; l <= i; l++) {
			for (int r = 1; r <= i; r++) {
				__int128 sum_with_multiplication = (S[r] - S[l - 1]) * C + S[i] - S[r];
				__int128 sum_without_multiplication = S[i] - S[l - 1];

				dp[i] = max(dp[i], S[l - 1] + max(sum_with_multiplication, sum_without_multiplication));
			}
		}
	}
	cout << dp[N] << endl;


	return 0;
}