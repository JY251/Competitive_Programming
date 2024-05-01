#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<char>> A(N, vector<char>(N, 0));
	vector<vector<char>> B(N, vector<char>(N, 0));

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
				cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}