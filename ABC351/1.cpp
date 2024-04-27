#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> A(9, 0);
	vector<int> B(8, 0);

	int score_A = 0;
	int score_B = 0;

	for (int i = 1; i <= 9; i++) {
		// i is 1-indexed; A is 0-indexed
		cin >> A[i-1];
		score_A += A[i-1];
	}
	for (int i = 1; i<= 8; i++) {
		// i is 1-indexed; B is 0-indexed
		cin >> B[i-1];
		score_B += B[i-1];
	}

	int diff = score_A - score_B + 1;
	cout << diff << endl;

	return 0;
}