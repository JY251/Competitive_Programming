#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
				// NOTE: After s.erase, the size of s is changed,
				//  so you don't to need about the end condition of the loop.
        for (int i=0; i<(int)s.size(); i++) {
					if ('0' <= s[i] && s[i] <= '9') {
					// if (('a' <= s[i] && s[i] <= 'z') || ('A" <= s[i]' && s[i] <= 'Z')) {
						s.erase(s.begin() + i);
						s.erase(s.begin() + i -1);
						i-=2; // two elements are removed, so i will be smaller by 2.
						// ab34 (now 3) -> a4: You should be in pos 2: 
						// since i++ is done in the loop, i should be 1 in the end of the loop
					}
				}
				return s;
    }
};