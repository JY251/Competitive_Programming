#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> A(N, vector<int>(N, 0));
	vector<vector<int>> B(N, vector<int>(N, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i-1][j-1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> B[i-1][j-1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i-1][j-1] != B[i-1][j-1]) {
				cout << i-1 << " " << j-1 << endl;
			}
		}
	}
	return 0;
}