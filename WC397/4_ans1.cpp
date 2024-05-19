// 3147. Taking Maximum Energy From the Mystic Dungeon
// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/solutions/5145835/the-best-explanation-beats-100-users
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumEnergy(vector<int>& energy, int k) {
		int n=energy.size(), ans=INT_MIN;
		vector<int> dp(n, INT_MIN);
		dp[n-1]=energy[n-1];
		ans=max(ans, dp[n-1]);
		for (int i=n-2;i>=0;i--) {
			if (i+k<n) dp[i]=max(dp[i], energy[i]+dp[i+k]);
			else dp[i]=energy[i];
			ans=max(ans, dp[i]);
		}
		return ans;
	}
};