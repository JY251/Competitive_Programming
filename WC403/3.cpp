// Sub1: WA
// https://leetcode.com/contest/weekly-contest-403/problems/minimum-average-of-smallest-and-largest-elements/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
		int pop_max(vector<int>& nums) {
			int max = 0;
			int max_index = 0;
			for (int i=0; i<(int)nums.size(); i++) {
				if (nums[i] > max) {
					max = nums[i];
					max_index = i;
				}
			}
			nums.erase(nums.begin() + max_index);
			return max;
		}

		int pop_min(vector<int>& nums) {
			int min = 0;
			int min_index = 0;
			for (int i=0; i<(int)nums.size(); i++) {
				if (nums[i] < min) {
					min = nums[i];
					min_index = i;
				}
			}
			nums.erase(nums.begin() + min_index);
			return min;
		}

		double find_min_double(vector<double>& nums) {
			double min = 0;
			int min_index = 0;
			for (int i=0; i<(int)nums.size(); i++) {
				if (nums[i] < min) {
					min = nums[i];
					min_index = i;
				}
			}
			return min;
		}

    double minimumAverage(vector<int>& nums) {
				vector<double> averages;
				for (int i=0; i<(int)nums.size()/2; i++) {
					int max = pop_max(nums);
					int min = pop_min(nums);
					averages.push_back((double)(max + min) / 2.0);

				}
				int min_avg = find_min_double(averages);
				return min_avg;
    }
};