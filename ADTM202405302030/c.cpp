#include <iostream>
// #include <cmath>
using namespace std;

int main() {
	int a, b, k;
	cin >> a >> b >> k;

	// a * k ** ans = b
	// k ** ans = b / a
	// int ans;
	// ans = clog(b/a)

	int curr = a;
	int count = 0;
	while (curr < b) {
		curr *= k;
		count++;
	}
	cout << count << endl;

	return 0;
}