#include <bits/stdc++.h>
using namespace std;
class Solution {
struct Point {
	char tag;
	vector<int> coordinates;
	int dist;
};

public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
				vector<Point> points_with_tag(s.size());
				for (int i = 0; i < (int)s.size(); i++) {
					points_with_tag[i].tag = s[i];
					points_with_tag[i].coordinates = points[i];
					points_with_tag[i].dist = distance(points[i]);
				}

				// sort the points by distance from (0, 0) in the accending order
				sort(points_with_tag.begin(), points_with_tag.end(), [](Point& p1, Point& p2){
					return p1.dist < p2.dist;
				}); 

				// for (int  i = 0; i < (int)s.size(); i++) {
				// 	cout << points_with_tag[i].tag << " " << points_with_tag[i].coordinates[0] << " " << points_with_tag[i].coordinates[1] << endl;
				// }


				unordered_map<char, bool> already_appeared;
				// Initialize already_appeared
				for (int i = 0; i < (int)s.size(); i++) {
					already_appeared[points_with_tag[i].tag] = false;
				}

				int count = 0;

				// search from nearest to farthest: if the points have the same tag with already-visited points, then that is the maximum square
				int i = 0;
				for (i = 0; i < (int)s.size(); i++) {
					if (already_appeared[points_with_tag[i].tag]) {
						break;
					} else {
						already_appeared[points_with_tag[i].tag] = true;
						count++;
						continue;
					}
				}

				// the case there are two points with the same distance from (0, 0)
				//////
				// a 2 2
				// b -1 -2
				// c -3 1
				// a 3 -3
				// d -4 4
				//////
				// the above case, for loop breaks  in (3，-3) and it returns 3, but actually (-3, 1) has the same distance from (0, 0) with (3, -3) so this points should not be included in the maximum square.
				while(points_with_tag[i].dist == points_with_tag[i-1].dist) {
					i--;
					count--;
				}

				return count;
    }
		// without static, the following fun cannot be used in `sort`.
		// non-static member function does belong to some specific object but static member function does not belong to any object and can be called without any object.
		static int distance(vector<int>& point) {
			return (abs(point[0])) > (abs(point[1])) ? abs(point[0]) : abs(point[1]);
		}
};

int main() {
	Solution solution;
	vector<vector<int>> points = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
;
	string s = "abdca";
	cout << solution.maxPointsInsideSquare(points, s) << endl;
	return 0;
}