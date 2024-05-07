#include <iostream>

using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;

	if (Y <= X) {
		cout << 0 << endl;
	} else {
		// X < Y
		int additionals = (Y - X) / 10 + ((Y - X) % 10 != 0);
		cout << additionals << endl;
	}

	return 0;
}