#include <iostream>

using namespace std;

int main() {
	int W, B;
	cin >> W >> B;

	int wb_count = min(W, B) * 2;

	if (W == wb_count && B == wb_count/2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}