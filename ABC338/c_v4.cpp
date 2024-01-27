#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_servings(vector<int>& Q, vector<int>& A, vector<int>& B) {
	int N = Q.size();

	vector<int> max_per_ingredient(N, 0);

	for (int i = 0; i < N; i++) {
		max_per_ingredient[i] = Q[i] / A[i];
	}

	int max_servings = *min_element(max_per_ingredient.begin(), max_per_ingredient.end());

	vector<int> dp(max_servings, 0);

	dp[0] = max_servings;
	for (int i = 0; i < max_servings; i++) {
		int max_servings_A = dp[0] - i;

		vector<int> max_per_ingredient_B(N, 0);
		for (int j = 0; j < N; j++) {
			max_per_ingredient_B[j] = (Q[j] - max_servings_A * A[j]) / B[j];
		}
		int max_servings_B = *min_element(max_per_ingredient_B.begin(), max_per_ingredient_B.end());

		dp[i] = max_servings_A + max_servings_B;
	}

	max_servings = *max_element(dp.begin(), dp.end());
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
