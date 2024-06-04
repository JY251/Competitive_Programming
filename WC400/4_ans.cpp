// https://leetcode.com/contest/weekly-contest-400/problems/count-days-without-meetings/
// Copied the following solution:
// https://leetcode.com/problems/count-days-without-meetings/solutions/5243315/greedy-merge-intervals
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b) {
	return a[0] < b[0];
}

class Solution {
	public:
		int countDays(int days, vector<vector<int>>& m) {
			int n = m.size();
			// <IMP> sorting: I have not come up with this idea
			sort(m.begin(), m.end(), cmp); // `bool cmp` is defined above (Used here)
			int count = 0;
			count += abs(m[0][0] - 1); // count the days before the first meeting (these days are days without meetings)
			for (int i=1; i<n; i++) {
				if (m[i][0] <= m[i-1][1]) { // if the meetings are overlapping
					if (m[i][1] < m[i-1][1]) m[i][1] = m[i-1][1]; // merge the two meetings
				}
				else {
					int dy = m[i][0] - m[i-1][1]; // the days between the two meetings
					count += dy - 1;
				}
			}
			count += days - m[n-1][1]; // count the days after the last meeting
			// count += abs(m[n-1][1] - days); // this is the one in the original solution
			return count;
		}
};