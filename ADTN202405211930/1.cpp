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

	// Improved Algorithm1:
	// the above case, see the row direction: 1, 1, 1 and 2, 0, 1 => if some of them are the same OK? 2-0 can be converted to 1-1 by shifting the column direction

	// Implementation of Algorithm1:
	// Count the number of # and . in the each row of a and of b
	vector<int> num_sharp_row_a(w, 0);
	vector<int> num_sharp_row_b(w, 0);
	for (int i=0; i<h; i++) {
		// int num_sharp_first_row_a = 0;
		// int num_dot_first_row_a = 0;
		for (int j=0; j<w; j++) {
			if (a[i][j] == '#') num_sharp_row_a[j]++;
		}
	}

	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (b[i][j] == '#') num_sharp_row_b[j]++;
		}
	}

	// Count the number of # and . in the each column of a and of b
	vector<int> num_sharp_column_a(h, 0);
	vector<int> num_sharp_column_b(h, 0);
	for (int j=0; j<w; j++) {
		for (int i=0; i<h; i++) {
			if (a[i][j] == '#') num_sharp_column_a[i]++;
		}
	}
	for (int j=0; j<w; j++) {
		for (int i=0; i<h; i++) {
			if (b[i][j] == '#') num_sharp_column_b[i]++;
		}
	}

	// Shift of the row direction: let the first row of a has `num_sharp_first_row_a`, shift b in row direction so that the first row of b has `num_sharp_first_row_a` #s.
	for (int s=0; s<h; s++) {
		if (num_sharp_row_b[s] == num_sharp_row_a[0]) {
			// check if other rows of a and b has the same number of #s and .s
			int is_num_sharp_row_same = true; // if there are any rows that are not the same, is_num_sharp_row_same will be false
			for (int i=1; i<h; i++) {
				// b[0] will be b[s]; b[1] will be b[s+1]; ... ; b[h-1] will be b[(s+h-1)%h]
				if (num_sharp_row_a[i] != num_sharp_row_b[(i+s)%h]) is_num_sharp_row_same = false;
			}
			// if not the same break
			if (is_num_sharp_row_same == false) break;

			// if the same continue to check the column direction
			// Shift of the column direction: let the first column of a has `num_sharp_first_column_a`, shift b in column direction so that the first column of b has `num_sharp_first_column_a` #s.
			for (int t=0; t<w; t++) {
				if (num_sharp_column_b[t] == num_sharp_column_a[0]) {
					// check if other columns of a and b has the same number of #s and .s
					int is_num_sharp_column_same = true;
					for (int j=1; j<w; j++) {
						// b[0] will be b[s]; b[1] will be b[s+1]; ... ; b[h-1] will be b[(s+h-1)%h]
						if (num_sharp_column_a[j] != num_sharp_column_b[(j+t)%w]) is_num_sharp_column_same = false;
					}
					// if not the same break
					if (is_num_sharp_column_same == false) break;

					// if the same, check each element of a and b
					int is_match = true; // if there are any elements that are not the same, is_match will be false
					for (int i=0; i<h; i++) {
						for (int j=0; j<w; j++) {
							if (a[i][j] != b[(i+s)%h][(j+t)%w]) is_match = false;
						}
					}
					if (is_match == true) {
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}