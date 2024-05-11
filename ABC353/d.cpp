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

	int sum = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i; j < n; j++) {
			stringstream ss;
			ss << a[i] << a[j]; // this is not str
			sum += stoi(ss.str());
		}
	}

	cout << sum << endl;


	return 0;
}