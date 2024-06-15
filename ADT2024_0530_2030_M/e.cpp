// Problm: https://atcoder.jp/contests/adt_medium_20240530_3/tasks/abc264_c
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int h1, w1;
	cin >> h1 >> w1;

	vector<vector<int>> a(h1, vector<int>(w1, 0));
	for (int i = 0; i < h1; i++) {
		for (int j = 0; j < w1; j++) {
			cin >> a[i][j];
		}
	}

	int h2, w2;
	cin >> h2 >> w2;

	vector<vector<int>> b(h2, vector<int>(w2, 0));
	for (int i=0; i<h2; i++) {
		for (int j=0; j<w2; j++) {
			cin >> b[i][j];
		}
	}

	return 0;
}