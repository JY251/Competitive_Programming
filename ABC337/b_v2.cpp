#include <iostream>
#include <string>

using namespace std;

bool isContinuousABC(const string& s) {
	if (s.empty()) {
		return true;
	}

	char firstChar = s[0];
	char secondChar = 0;
	size_t firstLen = 0;
	size_t secondLen = 0;

	for (char c : s) {
		if (c != firstChar) {
			secondChar = c;
			break;
		}
	}

	for (char c: s) {
		if (c != secondChar) {
			break;
		}
	}
}