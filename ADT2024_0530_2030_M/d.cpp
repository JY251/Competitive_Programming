// Problem: https://atcoder.jp/contests/adt_medium_20240530_3/tasks/abc259_b
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int a, b, d;
	cin >> a >> b >> d;

	vector<vector<int>> rotation_mtx = vector<vector<int>>(2, vector<int>(2, 0));

	double d_radian = d / (double)180 * M_PI;

	rotation_mtx[0][0] = cos(d_radian);
	rotation_mtx[0][1] = -sin(d_radian);
	rotation_mtx[1][0] = sin(d_radian);
	rotation_mtx[1][1] = cos(d_radian);

	double a_dash = cos(d_radian) * (double)a - sin(d_radian) * (double)b;
	double b_dash = sin(d_radian) * (double)a + cos(d_radian) * (double)b;

	cout << a_dash << " " << b_dash << endl;

	return 0;
}