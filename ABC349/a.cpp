#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int scores[N-1];
	for (int i = 0; i < N-1; i++) {
		cin >> scores[i];
	}

	for (int i = 0; i < N; ++i) {
		scores[i] += N - i;
	}

	int final_score_N = max(0, min(scores[0], 100));

	for (int i = 1; i < N - 1; ++i) {
		final_score_N = max(final_score_N, min(scores[i], 100));
	}

	cout << final_score_N << endl;

	return 0;
}