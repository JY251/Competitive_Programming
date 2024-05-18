#include <iostream>
// #include <cmath>
using namespace std;

int main() {
	int h;
	cin >> h;

	int day = 0;
	int plant = 0;
	int increase = 1;
	while (plant <= h) {
		plant += increase;
		increase *= 2;
		day++;
	}

	cout << day << endl;
	return 0;
}