#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
				int max_total_energy = 0;
				for (int i = 1; i < energy.size(); i++) {
					// each case: start from i
					int total_energy = energy[i];
					while(i+k < energy.size()) {
						total_energy += energy[i+k];
						i += k;
					}

					if (total_energy > max_total_energy) {
						max_total_energy = total_energy;
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