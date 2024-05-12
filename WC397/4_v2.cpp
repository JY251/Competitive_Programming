#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
		vector<int> reverse(vector<int>& arr) {
			vector<int> reversed_arr;
			int n = arr.size();
			for (int i = 0; i < n; i++) {
				reversed_arr[i] = arr[n-i-1];
			}
			return reversed_arr;
		}

    int maximumEnergy(vector<int>& energy, int k) {
				vector<int> reversed_energy = reverse(energy);
				int max_total_energy;
				for (int i = 0; i < k; i++) {
					int total_energy = 0;
					// int naive_total_energy = 0;
					vector<int> total_energies;
					for (int j = i; j < (int)reversed_energy.size(); j+=k) {
						// naive_total_energy += energy[j];
						total_energy += reversed_energy[j];
						total_energies.push_back(total_energy);
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