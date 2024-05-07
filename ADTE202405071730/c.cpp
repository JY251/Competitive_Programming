#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> W(N);
	vector<int> X(N);

	for (int i = 0; i < N; i++) {
		cin >> W[i] >> X[i];
	}

	return 0;
}