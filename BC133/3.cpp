// AC
// https://leetcode.com/contest/biweekly-contest-133/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
				int count = 0;
        for (int i=0; i<nums.size(); i++) {
					if (nums[i]%3 == 0) {
						continue;
					} else count++; // if nums[i]%3 != 0 i.e., nums[i] % 3 == 1 or 2 -> just subtract 1 (is % 3 == 1) or add 1 (if % 3 == 2), thus both require 1 operation
				}
				return count;
    }
};