#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
				// unordered_map<char, int> max_dist_per_char;
				vector<int> dist_per_char(0);
				// vector<int> appreared_cnt(0); // count the number of appearance of each char
				for (int i = 0; i < s.size(); i++) {
					// dist(x, y) = max(abs(x), abs(y)) here: dist from (0, 0)
					int dist = (abs(points[i][0]) > abs(points[i][1])) ? abs(points[i][0]) : abs(points[i][1]);
					dist_per_char[i] = dist;
				}

				// sort the points by distance from (0, 0) in the accending order
				// search from nearest to farthest: if the points have the same tag with already-visited points, then that is the maximum square
				vector<int> 


        vector<int> flattened_dist = flattenArray(points);

				for (int i = findMax(flattened_dist, flattened_dist.size()); i >= 0; i--) {

				}
    }

		vector<int> flattenArray(vector<vector<int>>& arr) {
			vector<int>result;
			for (const auto& point: arr) {
				for (const auto& x: point) {
					// result.push_back(x);
					result.push_back(abs(x)); // push back abs val.
				}
			}
			return result;
		}

		int findMax(vector<int> arr, int n) {
			int max = arr[0];
			for (int i = 1; i < n; i++) {
				if (arr[i] > max) {
					max = arr[i];
				}
			}
			return max;
		}
};
