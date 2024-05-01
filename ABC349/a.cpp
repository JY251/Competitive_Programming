#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int scores[N-1];
	for (int i = 0; i < N-1; i++) {
		cin >> scores[i];
	}

	int final_score_N = 0;

	for (int i = 0; i < N - 1; ++i) {
		final_score_N += scores[i];
	}

	cout << (0 - final_score_N) << endl;

	return 0;
}