#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> S(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> S[i][j];
		}
	}

	int max_x, max_y;
	int max_free = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '.') {
				// the case
			}
		}
	}


	return 0;
}