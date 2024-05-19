// 100308. Special Array II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
				vector<bool> res((int)queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
					vector<int> subArray = vector<int>(nums.begin() + queries[i][0], nums.begin() + queries[i][1] + 1);
					res[i] = isArraySpecial_1(subArray);
				}
				return res;
    }

    bool isArraySpecial_1(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size()-1; i++) {
					if ((nums[i] % 2) == (nums[i+1] % 2)) {
						return false;
					}
				}
				return true;
    }
};