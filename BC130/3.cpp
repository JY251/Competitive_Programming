#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size()-1; i++) {
					for (int j = 0; j < grid[i].size(); j++) {
						if (grid[i][j] == grid[i+1][j]) {
							continue;
						} else {
							return false;
						}
					}
				}
				// since grid[i][j] = grid[i+1][j] for all j, i.e., grid[i][j] is the same for all i when j is fixed
				// we can just check the first row
				for (int j = 0; j < grid[0].size()-1; j++) {
					if (grid[0][j] != grid[0][j+1]) {
						continue;
					} else {
						return false;
					}
				}
				return true;
    }
};