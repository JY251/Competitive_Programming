#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string S;
	cin >> S;

	int n = S.size();
	vector<int> dp(n+1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (S[j-1] < S[i-1]) {
				dp[i] += dp[j];
			}
		}
	}

	cout << dp[n] << endl;
	return 0;
}