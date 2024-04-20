#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;

	string suffix = S.substr(3, 3);
	int num = stoi(suffix);
	if (num >= 1 && num <= 349 && num != 316) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}