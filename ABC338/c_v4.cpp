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

	int max_servings_A_init = *min_element(max_per_ingredient.begin(), max_per_ingredient.end());

	// cout << "max_servings (line 24): " << max_servings_A_init << endl; // OK


	if (max_servings_A_init == 0) {
		vector<int> max_per_ingredient_B_init(N, 0);
		for (int i = 0; i < N; i++) {
			if (B[i] != 0) {
				max_per_ingredient_B_init[i] = (Q[i]) / B[i];
			} else {
				max_per_ingredient_B_init[i] = INT_MAX;
			}
		}
		int max_servings_B_init = *min_element(max_per_ingredient_B_init.begin(), max_per_ingredient_B_init.end());
		return max_servings_B_init;
	}

	vector<int> dp(max_servings_A_init, 0);

	vector<int> max_per_ingredient_B_init(N, 0);
	for (int i = 0; i < N; i++) {
		if (B[i] != 0) {
			max_per_ingredient_B_init[i] = (Q[i] - max_servings_A_init * A[i]) / B[i];
		} else {
			max_per_ingredient_B_init[i] = INT_MAX;
		}
	}

	int max_servings_B_init = *min_element(max_per_ingredient_B_init.begin(), max_per_ingredient_B_init.end());

	dp[0] = max_servings_A_init + max_servings_B_init;

	
	for (int i = 1; i < max_servings_A_init; i++) {
		int max_servings_A = max_servings_A_init - i;

		vector<int> max_per_ingredient_B(N, 0);
		for (int j = 0; j < N; j++) {
			if (B[j] != 0) {
				max_per_ingredient_B[j] = (Q[j] - max_servings_A * A[j]) / B[j];
			} else {
				max_per_ingredient_B[j] = INT_MAX;
			}

			
			// cout << "max_per_ingredient_B[" << j << "]: " << max_per_ingredient_B[j] << endl; // OK
		}
		int max_servings_B = *min_element(max_per_ingredient_B.begin(), max_per_ingredient_B.end());

		// cout << "max_servings_B (line 40): " << max_servings_B << " j: " << i << endl; // OK

		// cout << "max_servings_A (line 42): " << max_servings_A << " j: " << i << endl; // OK

		dp[i] = max_servings_A + max_servings_B;
	}

	int max_servings = *max_element(dp.begin(), dp.end());

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
