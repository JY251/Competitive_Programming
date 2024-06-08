#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	// NOTE: 'A': 65, 'a': 97 (Upper case is smaller than lower case, so not to confuse that 'A' is larger than 'a')
	for (int i=0; i<(int)s.size(); i++) {
		if ('Z'>= s[i] && s[i] >= 'A') {
			s[i] = s[i] - 'A' + 'a';
		}
	}
	cout << s << endl;
	return 0;
}