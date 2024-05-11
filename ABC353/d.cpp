#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long sum = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i; j < n; j++) {
			stringstream ss;
			ss << a[i] << a[j]; // this is not str
			// a[i], a[j] is 10^9.3 at most (int), so stoi(ss.str()) is 10^18.6 at most: overflow for int; long (2^63 = 10^18.9) is OK
			// no function like stol?
			sum += stol(ss.str());
		}
	}

	cout << sum << endl;


	return 0;
}