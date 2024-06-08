#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        for (int i=0; i<(int)s.size(); i++) {
					if ('0' <= s[i] && s[i] <= '9') {
					// if (('a' <= s[i] && s[i] <= 'z') || ('A" <= s[i]' && s[i] <= 'Z')) {
						s.erase(s.begin() + i);
						s.erase(s.begin() + i -1);
					}
				}
				return s;
    }
};