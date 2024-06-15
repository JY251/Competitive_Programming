#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;
	int a, b;
	cin >> a >> b;

	// NOT TO FORGET
	a = a - 1;
	b = b - 1;

	char t = S[a];
	// char sb = S[b];

	S[a] = S[b];
	S[b] = t;

	cout << S << endl;

	return 0;

}