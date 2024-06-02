// https://leetcode.com/contest/weekly-contest-400/problems/count-days-without-meetings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
			vector<int> v(days, 0);
			for (auto m: meetings) {
				for (int i=m[0]; i<=m[1]; i++) {
					v[i-1] = 1; // m is 1-indexed but v is 0-indexed
				}
			}
			cout << endl;
			int ans = 0;
			for (int i=0; i<days; i++) {
				ans += (v[i] == 0);
			}
			return ans;
    }
};

int main() {
	Solution s;
	vector<vector<int>> mtgs = {{5, 7}, {1, 3}, {9, 10}};
	cout << s.countDays(10, mtgs) << endl;
	return 0;
}