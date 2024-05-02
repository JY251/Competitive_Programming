#include <iostream>
#include <string>

using namespace std;

int main() {
	int w, b;
	cin >> w >> b;

	string target = "wbwbwwbwbwbw";
	int target_len = target.size();

	int keyword_len = w + b;

	bool answer = true;

	for (int i = 0; i < target_len; i++) {
		int count = 0; // count of w
		for (int k = 0; k < keyword_len; k++) {
			if (i + k < target_len) {
				if (target[i + k] == 'w') {
					count++;
					if (count == w + 1) {
						answer = false;
						break;
					}
				}
			} else {
				if (target[i + k - target_len] == 'w') {
					count++;
					if (count == w + 1) {
						answer = false;
						break;
					}
				}
			}
		}
		if (count != w) {
			answer = false;
		} else {
			answer = true;
			break;
		}
	}

	if (answer) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}


	return 0;
}