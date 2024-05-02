#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i < 10; i++) {
		cout << i*10 << endl;
		if (i == 5) {
			break;
		}
		for (int j = 1; j < 10; j++) {
			cout << i*10 + j << endl;
			if (j == 5) {
				break;
			}
		}
	}
	return 0;
}