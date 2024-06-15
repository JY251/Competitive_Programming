#include <iostream>

using namespace std;

int main() {
	int X, Y, N;
	cin >> X >> Y >> N;


	if (3*X > Y) { // the case buy 3-set in Y yen is cheaper
		cout << (N / 3) * Y + (N % 3) * X << endl;
	} else {
		cout << N * X << endl;
	}

	return 0;
}