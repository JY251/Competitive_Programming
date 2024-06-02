// https://leetcode.com/contest/weekly-contest-400/problems/minimum-number-of-chairs-in-a-waiting-room/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
			int curr_count = 0;
			int max_count = 0;
			for (int i=0; i<(int)s.size(); i++) {
				if (s[i] == 'E') {
					curr_count++;
					if (curr_count > max_count) {
						max_count = curr_count;
					}
				} else {
					curr_count--;
				}
			}
			return max_count;
    }
};