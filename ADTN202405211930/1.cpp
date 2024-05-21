#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	 vector<vector<char>> a(h, vector<char>(w));
	 vector<vector<char>> b(h, vector<char>(w));

	 for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> a[i][j];
		}
	 }

	 for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> b[i][j];
		}
	 }

	// Algorithm1: 
	// assume that the number of # and . in either line of a and either line of b are the same; so does the number of # and . in either column of a and either column of b
	// by the above, we can make "match" each corresponding column and row of a and b

	// However, this is wrong since the following case is "Yes" though the above assumption is not satisfied
	// ###
	// ...

	// .##
	// .#.

	// Count the number of # and . in the first row of a and all the rows of b

	// Shift of the row direction: let the first row of a has `num_sharp_first_row_a`, shift b in row direction so that the first row of b has `num_sharp_first_row_a` #s.
		// check if other rows of a and b has the same number of #s and .s

		// if not the same break

		// if the same continue to check the column direction
		// Count the number of # and . in the first column of a and all the columns of b

		// Shift of the column direction: let the first column of a has `num_sharp_first_column_a`, shift b in column direction so that the first column of b has `num_sharp_first_column_a` #s.
			// check ...

}