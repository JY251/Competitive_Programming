#include <iostream>
#include <vector>

using namespace std;

pair<int, int> mostDistantMod(const vector<int>& nums, int mod) {
	vector<vector<int>> mods;

	for (int i = 0; i < nums.size(); i++) {
		int remainder = nums[i] % mod;
		mods[remainder].push_back(i);
	}

	if (!)
}


int main() {
	int N, A, B;
	cin >> N >> A >> B;

	vector<int> D(N);
	for (int i = 0; i < N; i++) {
		cin >> D[i];
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