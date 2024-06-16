// https://leetcode.com/contest/weekly-contest-402/problems/count-pairs-that-form-a-complete-day-i/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
				int count = 0;
        for (int i=0; i<hours.size(); i++) {
					for (int j=i+1; j<hours.size(); j++) {
						if (i != j && (hours[i] + hours[j])%24 == 0) {
							count ++;
						}
					}
				}
				return count;
    }
};

int main() {
	Solution s;
	vector<int> hours = {11, 11, 24};
	cout << s.countCompleteDayPairs(hours) << endl;
	return 0;
}