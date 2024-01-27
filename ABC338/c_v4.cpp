#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int max_servings(vector<int>& Q, vector<int>& A, vector<int>& B) {
	int N = Q.size();

	vector<int> max_per_ingredient(N, 0);

	for (int i = 0; i < N; i++) {
		if (A[i] != 0) {
			max_per_ingredient[i] = Q[i] / A[i];
		} else {
			max_per_ingredient[i] = INT_MAX;
		}
	}

	int max_servings = *min_element(max_per_ingredient.begin(), max_per_ingredient.end());

	// cout << "max_servings (line 24): " << max_servings << endl; // OK

	vector<int> dp(max_servings, 0);

	dp[0] = max_servings;
	for (int i = 1; i < max_servings; i++) {
		int max_servings_A = dp[0] - i;

		vector<int> max_per_ingredient_B(N, 0);
		for (int j = 0; j < N; j++) {
			if (B[j] != 0) {
				max_per_ingredient_B[j] = (Q[j] - max_servings_A * A[j]) / B[j];
			} else {
				max_per_ingredient_B[j] = INT_MAX;
			}
			// max_per_ingredient_B[j] = (Q[j] - max_servings_A * A[j]) / B[j];
		}
		int max_servings_B = *min_element(max_per_ingredient_B.begin(), max_per_ingredient_B.end());

		// cout << "max_servings_A (line 42): " << max_servings_A << " j: " << i << endl; // OK

		dp[i] = max_servings_A + max_servings_B;
	}

	max_servings = *max_element(dp.begin(), dp.end());

	// for (int i = 0; i < max_servings; i++) {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	return max_servings;
}

int main() {
	int N;
	cin >> N;

	vector<int> Q(N);
	for (int i = 0; i < N; i++) {
		cin >> Q[i];
	}

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	cout << max_servings(Q, A, B) << endl;
	return 0;
}
