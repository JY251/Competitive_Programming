#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

	dp[0][0] = 1;

	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=0; k<=j; k++ {
				dp[i][j] = 
			})
		}
	}
}