#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> A(M), B(M);

	for (int i = 0; i < M; i++) {
		cin >> A[i] >> B[i];
	}
	
	return 0;
}