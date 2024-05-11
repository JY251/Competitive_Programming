#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
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
