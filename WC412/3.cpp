// https://leetcode.com/contest/weekly-contest-412/problems/final-array-state-after-k-multiplication-operations-i/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i=0; i<k; i++) {
					// find the min element (if there is multiple, choose the leftmost)
					// NOTE: min_element returns not pointer, but iterator
					// auto minElement = min_element(nums.begin(), nums.end());
					vector<int>::iterator minElement = min_element(nums.begin(), nums.end());
					//  multiply the min element by multiplier
					*minElement *= multiplier;
				}
				return nums;
    }
};