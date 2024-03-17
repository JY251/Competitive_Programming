#include <iostream>
#include <vector>

using namespace std;

vector<long long> cumulative_sum(const vector<int> &A) {
	vector<long long> S(A.size() + 1, 0);
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

	vector <long long> S = cumulative_sum(A);
	for (int i = 0; i <= N; i++) {
		cout << S[i] << " ";
	}
	cout << endl;

	vector <long long> dp(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		for (int l = 1; l <= i; l++) {
			for (int r = 1; r <= i; r++) {
				long long sum_with_multiplication = (S[r] - S[l - 1]) * C + S[i] - S[r];
				long long sum_without_multiplication = S[i] - S[l - 1];

				dp[i] = max(dp[i], S[l - 1] + max(sum_with_multiplication, sum_without_multiplication));
				// debug
				for (int i = 0; i <= N; i++) {
					cout << dp[i] << " ";
				}
				cout << "(i = " << i << ", l = " << l << ")";
				cout << "; (sum_with_multiplication = " << sum_with_multiplication << ", sum_without_multiplication = " << sum_without_multiplication << ")";
				cout << endl;
			}
		}
	}
	cout << dp[N] << endl;


	return 0;
}