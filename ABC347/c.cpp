#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pair<int, int> mostDistantMod(const vector<int>& nums, int mod) {
bool mostDistantMod(const vector<int>& nums, int mod, int range) {
	vector<int> nums_mods(nums.size());
	for (long unsigned int i = 0; i < nums.size(); i++) {
		nums_mods[i] = nums[i] % mod;
	}

	int max_distance = max_element(nums_mods.begin(), nums_mods.end()) - min_element(nums_mods.begin(), nums_mods.end());

	if (max_distance >= range && (mod - max_distance) >= range) {
		return false;
	} else {
		return true;
	}
}


int main() {
	int N, A, B;
	cin >> N >> A >> B;

	vector<int> D(N);
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}

	bool NotOverHoliday = mostDistantMod(D,A+B, A);

	if (!NotOverHoliday) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < A+B; i++) {
		bool is_all_holiday = true;
		for (int j = 0; j < N; j++) {
			if ((i + D[j]) % (A+B) >= A) {
				is_all_holiday = false;
				break;
			}
		}
		if (is_all_holiday == true) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}