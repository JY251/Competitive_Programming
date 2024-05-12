#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
				int max_total_energy;
				for (int i = 0; i < k; i++) {
					int total_energy = 0;
					// max index is i + ((int)energy.size()-i) % k)*k: 
					// if there are 5 elements and k = 3, if i = 0, the max index is 3, if i = 1, the max index is 4
					// i = 0: 0 + (5-1) % 3)*3 = 3
					// i = 1: 1 + (5-2) % 3)*3 = 4
					// i = 2: 2 + (5-3) % 3)*3 = 2
					// i = 3: 3 + (5-4) % 3)*3 = 3
					// i = 4: 4 + (5-5) % 3)*3 = 4
					cout << "Energy size: " << energy.size() << ", k: " << k << endl;
					cout << ((int)energy.size()-(i+1)) << endl;
					cout << "i: " << i << ", " << ((int)energy.size()-(i+1)) % k << endl;
					cout << "(start) - i: " << i << ", " << i + (((int)energy.size()-(i+1)) % k)*k << endl;
					for (int j = i + (((int)energy.size()-(i+1)) % k)*k; j >= 0; j-=k) {
						cout << "i: " << i << ", j: " << j << endl;
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