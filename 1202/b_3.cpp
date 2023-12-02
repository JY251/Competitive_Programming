#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	int N, S, M, L;
	cin >> N >> S >> M >> L;

	vector<int> dp(N+1, INT_MAX);
	dp[0] = 0;

	for (int i = 6; i<=12; i++) {
		for (int j = 0; j <= N; j++) {
			dp[j] = min(
				dp[j],
				dp[j-i] + ((i/6) * S + ((i%6) == 0? 0 : M) + ((i % 6))>2 ? L:0)
			);
		}
	}

	cout << dp[N] << endl;
	return 0;
}