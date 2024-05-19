// 3143. Maximum Points Inside the Square
// Copied of the following solution:
// https://leetcode.com/problems/maximum-points-inside-the-square/solutions/5144889/biweekly-130-fastest-100-easy-clean-multiple-approaches
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
		// store the minimum distance from (0, 0) for each character
		unordered_map<char, int> minLens;
		int secondMin = INT_MAX, count = 0; // secondMin is the allowed maximum square

		for (size_t i = 0; i < points.size(); ++i) {
			// the minimum square which can contain the point (len-1 is the maximum square which does not contain the point)
			int len = max(abs(points[i][0]), abs(points[i][1])); 
			char c = s[i];

			if (minLens.find(c) == minLens.end()) {
				minLens[c] = len;
			} else if (len < minLens[c]) {
				// the case current point is closer than the previous point with same tag
				// therefore, the maximum square should be less than minLens[c]
				secondMin = min(secondMin, minLens[c]);
				minLens[c] = len; // update minLens[c] since we found a smaller len
			} else { 
				// the case current point is farther than the previous point with same tag
				// therefore, the maximum square should be less than `len`
				secondMin = min(secondMin, len);
			}
		}

		for (auto& pair: minLens) {
			if (pair.second < secondMin) {
				count++;
			}
		}

		return count;
	}
};