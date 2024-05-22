// 100308. Special Array II
// Copied of the following solution:
// https://leetcode.com/problems/special-array-ii/solutions/5177107/explained-convert-the-array-ii
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
			vector<bool> ans;
			vector<int> converted(1, 0);
			for (int i=1, j=0; i<nums.size(); ++i) {
				if (nums[i]%2 == nums[i-1]%2) j++;
				converted.push_back(j);
			}
			// Check the converted array
			for (int i=0; i<converted.size(); ++i) cout << converted[i] << " ";
			cout << endl;
			for (auto q:queries) ans.push_back(converted[q[0]] == converted[q[1]]);
			return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {4, 3, 1, 6};
	vector<vector<int>> queries = {{0, 2}, {2, 3}};
	vector<bool> ans = sol.isArraySpecial(nums, queries);
	for (auto a:ans) cout << a << " ";
	cout << endl;
	return 0;
}