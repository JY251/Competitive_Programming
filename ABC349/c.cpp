#include <iostream>
#include <string>
#include <vector>

using namespace std;

// bool isAirportCode(string s, string t, int n) {
bool isAirportCode(string &s, string &t, int n) { // ポインタ型にしたほうが良い（それでも 3/48 caseでWAになる）
	// check if t is a length 3 substring of s
	// long unsigned int
	size_t j = 0;
	cout << s.size() << endl;
	for (int i = 0; i < n; i++) {
		if (isupper(t[i])) {
		} else {
			return false;
		}
		for (; j < s.size(); j++) {
			if (t[i] == s[j]  + 'A' - 'a' ) {
				if (i == n-1) {
					return true;
				}
				j++; 
				// 本番はここで詰まりました。これがないと、3/48のテストケースでWAになります。
				// ここでjをincrementしないと、"bcc - BBC"のような場合を誤ってtrueとしてしまう
				// breakするため、jがincrementされず、次のループで同じ文字を見ることになる - Bが2回出現していると誤って判断され、BBCが部分列になっていると判断される
				// 一般にこのようなケースを防ぐために、オートマトンをはじめに作って考えると、場合分けの漏れがなくなる
				break;
			}
		}
	}
	return false;
}

int main() {
	string s, t;
	cin >> s >> t;

	bool isTrue;
	if (t.size() != 3) {
		isTrue = false;
	} else {
	bool isTrue3 = isAirportCode(s, t, 3);
	bool isTrue2 = isAirportCode(s, t, 2) && t[2] == 'X';
	// bool isTrue2 = isAirportCode(s, t, 2);
	isTrue = isTrue3 || isTrue2;
	// isTrue = isTrue3;
	// isTrue = isTrue2;
	}

	
	if (isTrue) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}