#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int N;
	cin >> N;

	string S;
	cin >> S;

	vector<int> C(N);
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	vector<int> P(N);
	for (int i = 1; i < N; i++) {
		int j = P[i-1];
		while (j > 0 && S[i] != S[j]) {
			j = P[j-1];
		}
		P[i] = (S[i] == S[j]) ? j+1 : 0;
	}

	vector<int> T(N+1, INT_MAX);
	T[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int flip_cost = C[i - 1] * (S[i - 1] != S[j - 1]);

			T[i] = min(T[i], T[j - 1] + flip_cost);
		}
	}

	int answer = T[N];

	cout << answer << endl;
	return 0;
}