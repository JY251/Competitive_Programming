#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> a(64);

	for (int i = 0; i < 64; i++) {
		cin >> a[i];
	}

	int power = 1;

	long x = 0;

	for (int i = 0; i < 64; i++) {
		x += (long)power * (long)a[i];
		power *= 2;
	}

	cout << x << endl;

	return 0;
}