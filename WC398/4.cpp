// 100308. Special Array II
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
				vector<bool> res((int)queries.size());
				vector<int> indices_cannot_over = isArraySpecial_1(nums);
				// for (int i = 0; i < (int)indices_cannot_over.size(); i++) {
				// 	cout << indices_cannot_over[i] << " ";
				// }
				// cout << endl;
        for (int i = 0; i < (int)queries.size(); i++) {
					res[i] = true;
					vector<int> subArray = vector<int>(nums.begin() + queries[i][0], nums.begin() + queries[i][1] + 1);
					for (int j = 0; j < (int)indices_cannot_over.size(); j++) {
						if (queries[i][0] != queries[i][1]) {
							if (queries[i][0] <= indices_cannot_over[j] && indices_cannot_over[j] <= queries[i][1]) {
								res[i] = false;
							}
						}
					}
				}
				return res;
    }

    vector<int> isArraySpecial_1(vector<int>& nums) {
				vector<int> res; // res stores the indices of the elements that have the same parity with the next element
				int first_remainder = nums[0] % 2;
				int second_remainder;
        for (int i = 0; i < (int)nums.size()-1; i++) {
					second_remainder = nums[i+1] % 2;
					if (first_remainder == second_remainder) {
						res.push_back(i);
					}
					first_remainder = second_remainder;
				}
				return res;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {3, 4, 1, 2, 6};
	vector<vector<int>> queries = {{0, 4}};
	vector<bool> res = sol.isArraySpecial(nums, queries);

	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}