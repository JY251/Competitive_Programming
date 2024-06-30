// https://leetcode.com/contest/weekly-contest-404/problems/maximum-height-of-a-triangle/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
				int red_original = red;
				int blue_original = blue;
        // allocate red as root
				int iter = 1;
				while (red > 0 || blue > 0) {
					if (iter % 2 == 1) {
						red -= iter;
					} else {
						blue -= iter;
					}
					iter++;
				}
				int iter1 = iter - 1;

				// allocate blue as root
				red = red_original;
				blue = blue_original;
				iter = 1;
				while (red > 0 || blue > 0) {
					if (iter % 2 == 1) {
						blue -= iter;
					} else {
						red -= iter;
					}
					iter++;
				}
				return min(iter1, iter - 1);
    }
};

int main() {
	Solution sol;
	cout << sol.maxHeightOfTriangle(2, 4) << endl;
}
