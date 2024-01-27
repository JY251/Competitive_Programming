#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_servings(const vector<int>& quantities, const vector<int>& dish_a, const vector<int>& dish_b) {
	int total_servings = 0;

	for (int i = 0; i < quantities.size(); i++) {
		int max_a = quantities[i] / dish_a[i];

		int max_b = quantities[i] / dish_b[i];

		int best_servings = max(max_a, max_b);

		total_servings += best_servings;
	}

	return total_servings;
}

int main() {
	int N;
	cin >> N;

	vector<int> quantities(N);
	for (int i = 0; i < N; i++) {
		cin >> quantities[i];
	}

	vector<int> dish_a(N);
	for (int i = 0; i < N; i++) {
		cin >> dish_a[i];
	}

	vector<int> dish_b(N);
	for (int i = 0; i < N; i++) {
		cin >> dish_b[i];
	}

	int max_people = max_servings(quantities, dish_a, dish_b);

	cout << max_people << endl;

	return 0;
}