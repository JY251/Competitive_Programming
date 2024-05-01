#include <iostream>

using namespace std;

int main() {
	int X;
	cin >> X;

	
	if (X % 10 != 0) {
		cout << X / 10 + 1 << endl;
	} else {
		cout << X / 10 << endl;
	}

	return 0;
}