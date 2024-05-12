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
					int total_energy = energy[i];
					while(i+k < (int)energy.size()) {
						total_energy += energy[i+k];
						i += k;
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
	vector<int> energy = {-2, -3, -1};
	int k = 2;
	Solution sol;
	cout << sol.maximumEnergy(energy, k) << endl;
	return 0;
}