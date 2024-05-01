// AC
#include <iostream>
#include <string>

using namespace std;

bool isExtendedABC(const string& s) {
	if (s.empty()) {
		return true;
	}

	const char* ptr = s.c_str();

	while (*ptr == 'A') {
		ptr++;
	}

	if (*ptr != 'B' && *ptr != 'C' && *ptr != '\0') {
		return false;
	}

	while ((*ptr == 'B')) {
		ptr++;
	}

	if (*ptr != 'C' && *ptr != '\0') {
		return false;
	}

	while (*ptr == 'C') {
		ptr++;
	}

	if (*ptr != '\0') {
		return false;
	}

	return true;
}

int main() {
	string s;
	cin >> s;

	bool result = isExtendedABC(s);

	if (result) {
		cout << "Yes" << endl;
	}	else {
		cout << "No"  << endl;
	}

	return 0;
}