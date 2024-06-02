// https://leetcode.com/contest/weekly-contest-400/problems/count-days-without-meetings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
			vector<int> v(days, 0);
			for (auto m: meetings) {
				for (int i=m[0]; i<=m[1]; i++) {
					v[i] = 1;
				}
			}
			int ans = 0;
			for (int i=0; i<days; i++) {
				ans += (v[i] == 0);
			}
			return ans;
    }
};