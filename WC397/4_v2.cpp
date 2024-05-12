#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
				int max_total_energy;
				for (int i = 0; i < k; i++) {
					int total_energy = 0;
					for (int j = i; j < (int)energy.size(); j+=k) {
						total_energy += energy[j];
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