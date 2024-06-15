#include <iostream>
#include <vector>
using namespace std;

int main() {
	int input;
	vector<int> a;
	do {
		cin >> input;
		a.push_back(input);
	} while(input != 0);

	// Not to forget a.size() minus 1
	for (int i = (int)a.size() - 1; i >= 0; i--) {
		cout << a[i] << endl;
	}

	return 0;
}