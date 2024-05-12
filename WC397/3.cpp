#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        // char, int, int
				unordered_map<char, pair<int, int>> data_char_pos;
				for (int i = 0; i < s.size(); i++) {
					data_char_pos[s[i]].first = i;
					data_char_pos[t[i]].second = i;
				}

				int ans = 0;
				for (auto &it: data_char_pos) {
					ans += abs(it.second.first - it.second.second);
				}
				return ans;
    }
};
