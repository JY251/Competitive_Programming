#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> carpet(int n) {

  char black = '#', white = '.';

  // Level-0
  if (n == 0) {
    return {{black}};
  }

  int carper_size = pow(3, n);

  // General case
  // Create the vector
  vector<vector<char>> board(
      carper_size,
      vector<char>(carper_size, white)); // initialize with white since the
                                         // central 3**(n-1)-square is all white

  // (0, 0), 						 (pow(3, n-1), 0),
  // (2*pow(3, n-1), 0) (0, pow(3, n-1))
  // (2*pow(3, n-1), pow(3, n-1)) (0, 2*pow(3, n-1)), (pow(3, n-1), 2*pow(3,
  // n-1)), (2*pow(3, n-1), 2*pow(3, n-1))
  vector<pair<int, int>> blocks = {
      {0, 0},
      {pow(3, n - 1), 0},
      {2 * pow(3, n - 1), 0},
      {0, pow(3, n - 1)},
			{2 * pow(3, n - 1), pow(3, n - 1)},
      {0, 2 * pow(3, n - 1)},
      {pow(3, n - 1), 2 * pow(3, n - 1)},
      {2 * pow(3, n - 1), 2 * pow(3, n - 1)}
		};

  for (auto &block : blocks) {
    // create (pow(3, n-1))-square block follows the rule
    vector<vector<char>> small_carpet = carpet(n - 1);

    // Allocate the small_carpet to the board
    for (int i = 0; i < pow(3, n - 1); i++) {
      for (int j = 0; j < pow(3, n - 1); j++) {
        board[block.first + i][block.second + j] = small_carpet[i][j];
      }
    }
  }

  return board;
}

int main() {
  int n;
  cin >> n;

  vector<vector<char>> board = carpet(n);

  for (int i = 0; i < pow(3, n); i++) {
    for (int j = 0; j < pow(3, n); j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}