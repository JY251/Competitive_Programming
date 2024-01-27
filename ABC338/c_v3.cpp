#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_servings(vector<int>& Q, vector<int>& A, vector<int>& B) {
	int n = Q.size();
	vector<int> dpA(n, 0), dpB(n, 0);
	dpA[0] = Q[0] / A[0];
	dpB[0] = Q[0] / B[0];

	for (int i = 1; i < n; i++) {
		dpA[i] = max(Q[i] / A[i], dpA[i - 1] + Q[i] / A[i]);
		dpB[i] = max(Q[i] / B[i], dpB[i - 1] + Q[i] / B[i]);
	}

	return *max_element(dpA.begin(), dpB.end()) + *max_element(dpB.begin(), dpB.end());
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
