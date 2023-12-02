#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<string> P(N);
	for (int i=0; i<N; i++) {
		cin >> P[i];
	}

	vector<vector<char>> grid(1e9, vector<char>(1e9));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			grid[i][j] = P[(j+1)%N][(i+1)%N];
		}
	}

	for (int q=0; q<Q; q++) {
		int A, B, C, D;
		cin >> A >> B >> C >> D;

		int blackCount = 0;
		for (int i=A-1; i<C; i++) {
			for (int j=B-1; j<D; j++) {
				if (grid[i][j] == 'B') {
					blackCount++;
				}
			}
		}

		cout << blackCount << endl;
	}

	return 0;
}