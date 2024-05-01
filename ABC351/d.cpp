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

	int max_freedom = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (S[i][j] == '#') {
				continue;
			}
			int freedom = 0;
			vector<vector<bool>> visited(H, vector<bool>(W, false));
			visited[i][j] = true;

			vector<int> dx = {0, 0, 1, -1};
			vector<int> dy = {1, -1, 0, 0};

			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] == '.') {
					visited[ni][nj] = true;
					freedom++;
					freedom+= dfs(ni, nj, S, visited);
				}
			}

			max_freedom = max(max_freedom, freedom);
		}
	}

	cout << max_freedom << endl;

	return 0;
}

int dfs(int i, int j, const vector<string>& S, vector<vector<bool>>& visited) {
	int H = S.size();
	int W = S[0].size();
	int freedom = 0;

	vector<int> dx = {0, 0, 1, -1};
	vector<int> dy = {1, -1, 0, 0};

	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];

		if (0 <= ni && ni < H && 0 <= nj && nj < W && S[ni][nj] == '.') {
			visited[ni][nj] = true;
			freedom++;
			freedom+= dfs(ni, nj, S, visited);
		}
	}

	return freedom;
}