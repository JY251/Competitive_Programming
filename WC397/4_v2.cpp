#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
				// set max as 0 initially will cause problem
				// if all elements are negative, the max will be 0 though the correct answer should be either the negative element
				int max_total_energy;
				for (int i = 0; i < (int)energy.size(); i++) {
					// each case: start from i
					int current_pos = i;
					int total_energy = energy[current_pos];
					current_pos += k;
					// Not to use i in the following: i is the iterator of the outer loop so it should not be changed in the inner loop
					// since i+k is not updated (you updates current_pos instead of i), this cause infinite while loop
					while(current_pos < (int)energy.size()) {
						// Not to make the following two lines vice versa: need to sum up the energy first before updating the current_pos
						total_energy += energy[current_pos];
						current_pos += k;
					}

					if (i == 0) {
						max_total_energy = total_energy;
					} else {
						if (total_energy > max_total_energy) {
							max_total_energy = total_energy;
						}
					}
				}
				return max_total_energy;
    }
};

int main() {
	vector<int> energy = {5, 2, -10, -5, 1};
	int k = 3;
	Solution sol;
	cout << sol.maximumEnergy(energy, k) << endl;
	return 0;
}