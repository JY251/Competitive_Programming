#include <iostream>
#include <vector>

using namespace std;

int main() {
	int H, W, K;
	cin >> H >> W >> K;

	vector<vector<char>> grid(H, vector<char>(W));
	// vector<string> grid(W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> grid[i][j];
		}
	}

	int minOperations = INT_MAX;

	// 	縦方向の操作
	for (int i = 0; i < H; ++i) {
		vector<string> tempGrid = grid;
		int operations = 0;

		for (int j = 0; j < W; ++j) {
			if ((i >> j) & 1) {
				for (int k = 0; k < W; ++k) {
					if (tempGrid[j][k] == '.') {
						tmpGrid[j][k] = 'o';
						operations++;
					}
				}
			}
		}

		for (int j = 0; j < W -K; ++j) {
			for 
		}
	}

	

	return 0;
}