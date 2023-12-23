#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long A;
	int M;
	long L, R;

	cin >> A >> M >> L >> R;

	int negative_tree = (A - L) / M;
	int positive_tree = (R - A) / M;

	cout << negative_tree << " ";
	cout << positive_tree;
	cout << endl;

	int trees = negative_tree + positive_tree + 1;

	cout << trees << endl;
	return 0;
}