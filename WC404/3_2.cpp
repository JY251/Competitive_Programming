// https://leetcode.com/contest/weekly-contest-404/problems/maximum-height-of-a-triangle/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
			// red as root
			// while 
				// if iter is 1, 3, ...: 
					// red -= iter
					// if red < 0: 
						// break
				// if iter is 2, 4, ...: 
					// blue -= iter
					// if blue < 0: 
						// iter1 = iter - 1
						// break


			// blue as root
    }
};

int main() {
	Solution sol;
	cout << sol.maxHeightOfTriangle(2, 4) << endl;
}
