#include <iostream>

using namespace std;

void nextDay(int y, int m, int d, int M, int D) {
	if (d < D) {
		cout << y << " " << m << " " << d + 1 << endl;
	} else if (m < M) {
		cout << y << " " << m + 1 << " " << 1 << endl;
	} else {
		cout << y + 1 << " " << 1 << " " << 1 << endl;
	}
}

int main() {
	int M, D, y, m, d;
	cin >> M >> D;
	cin >> y >> m >> d;

	nextDay(y, m, d, M, D);
	return 0;
}