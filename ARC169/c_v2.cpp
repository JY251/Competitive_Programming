#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, MOD = 998244353;
	cin >> N;
	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
	vector<int> A(N);

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=1; i<=N; i++) {
		if (A[i-1]==-1) {
			for (int j=1; j<=N; j++) {
				dp[i][j] = ()
			}
		}
	}
}
