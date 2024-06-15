// https://leetcode.com/contest/weekly-contest-401/problems/find-the-child-who-has-the-ball-after-k-seconds/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
				int current_pos = 0;
				int dir=1;
        for (int i=0; i<k; i++) {
					// current_pos in n-1 and dir = 1 -> -1
					if (current_pos == n-1 && dir == 1) {
						current_pos --;
						dir = -1;
					} else if (current_pos == 0 && dir == -1) {
						current_pos ++;
						dir = 1;
					// The following is not OK since it misses the initial case: current_pos = 0 and dir = 1
					// } else if (current_pos != 0) {
					} else {
						current_pos += dir;
					}
				}
				return current_pos;
    }
};

