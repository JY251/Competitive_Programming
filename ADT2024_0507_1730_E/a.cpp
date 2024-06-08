#include <iostream>

using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;

	if (X > Y) {
		// go down
		if (X - Y <= 3) {
			// by stairs
			cout << "Yes" << endl;
		} else {
			// by elevator
			cout << "No" << endl;
		}
	} else if (X < Y) {
		// go up
		if (Y - X <= 2) {
			// by stairs
			cout << "Yes" << endl;
		} else {
			// by elevator
			cout << "No" << endl;
		}
	}
	return 0;
}