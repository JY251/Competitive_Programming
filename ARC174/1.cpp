#include <iostream>
#include <vector>

using namespace std;

vector<long long> cumulative_sum(const vector<int> &A) {
	vector<long long> S(A.size() + 1, 0);
	S[0] = 0;
	for (int i = 1; i <= A.size(); i++) {
		S[i] = S[i - 1] + A[i-1];
	}
}

long long solve(const vector<int>& A, int C) {
	int N = A.size();
	vector<long long> S = cumulative_sum(A);
	vector<long long> dp(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		for (int l = 1; l <= i; l++){
			dp[i] = max(dp[i], dp[l - 1] + (S[i] - S[l - 1]) * C);
		}
	}

	return dp[N];
}

int main() {
	int N, C;
	cin >> N >> C;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector <long long> S = cumulative_sum(A);
	vector <long long> dp(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int l = 1; l <= i; l++) {
			dp[i] = max(dp[i], dp[l - 1] + (S[i] - S[l - 1]) * C);
		}
	}
	cout << dp[N] << endl;
	return 0;
}