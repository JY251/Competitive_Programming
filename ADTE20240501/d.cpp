#include <iostream>

using namespace std;

int main() {
	int X;
	cin >> X;

	int round = X / 10;
	if (X % 10 == 0) {
		cout << round << endl;
	} else {
		if (X > 0) {
			cout << round + 1 << endl;
		} else {
			cout << round << endl;
		}
	}

	return 0;
}