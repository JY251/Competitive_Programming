#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> X(n);
	vector<int> Y(n);

	int sum_x = 0;
	int sum_y = 0;
	int score_x, score_y;
	for (int i = 0; i < n; i++) {
		cin >> score_x >> score_y;
		sum_x += score_x;
		sum_y += score_y;
	}

	if (sum_x == sum_y) {
		cout << "Draw" << endl;
	} else if (sum_x > sum_y) {
		cout << "Takahashi" << endl;
	} else {
		cout << "Aoki" << endl;
	}

	return 0;
}