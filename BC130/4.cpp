#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
				vector<pair<char, vector<int>>> points_with_tag(s.size());
				for (int i = 0; i < s.size(); i++) {
					points_with_tag[i] = make_pair(s[i], points[i]);
				}
				// sort the points by distance from (0, 0) in the accending order
				sort(points_with_tag.begin(), points_with_tag.end(), compare_points_with_dist);


				unordered_map<char, bool> already_appeared;
				// Initialize already_appeared
				for (int i = 0; i < s.size(); i++) {
					already_appeared[points_with_tag[i].first] = false;
				}

				// search from nearest to farthest: if the points have the same tag with already-visited points, then that is the maximum square
				for (int i = 0; i < s.size(); i++) {
					if (already_appeared[points_with_tag[i].first]) {
						int dist = abs(points_with_tag[i].second[0]) > abs(points_with_tag[i].second[0]) ? abs(points_with_tag[i].second[0]) : abs(points_with_tag[i].second[0]);
						return dist - 1;
					} else {
						already_appeared[points_with_tag[i].first] = true;
						continue;
					}
				}
    }

		bool compare_points_with_dist(pair<char, vector<int>>& p1, pair<char, vector<int>>& p2) {
			// dist(x, y) = max(abs(x), abs(y)) here: dist from (0, 0)
			int dist1 = (abs(p1.second[0]) > abs(p1.second[1])) ? abs(p1.second[0]) : abs(p1.second[1]);
			int dist2 = (abs(p2.second[0]) > abs(p2.second[1])) ? abs(p2.second[0]) : abs(p2.second[1]);
			return dist1 < dist2; // sort in ascending order
		}
};
