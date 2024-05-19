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
				int first_remainder = nums[0] % 2;
				int second_remainder;
        for (int i = 0; i < (int)nums.size()-1; i++) {
					second_remainder = nums[i+1] % 2;
					if (first_remainder == second_remainder) {
						return false;
					}
					first_remainder = second_remainder;
				}
				return true;
    }
};