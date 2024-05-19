// Copy source code from https://atcoder.jp/contests/abc354/editorial/10002
#include <bits/stdc++.h>

using namespace std;

struct Card {
	int a; // Tsuyosa (JP: 強さ)
	int c; // Cost
	int index;
};

int main() {
	int n;
	cin >> n;
	vector<Card> cards(n);
	for (int i=0; i<n; i++) {
		int a, c;
		cin >> a >> c;
		cards[i] = {a, c, i};
	}

	// sort by c (cost) in ascending order
	sort(cards.begin(), cards.end(), [&](const auto&l, const auto&r){
		return l.c < r.c;
	});

	vector<int> ans;
	int v = 0;
	for (int i=0; i<n; i++) {
		// here is the point I have not come up with
		// Idea: remaing the card (I have considered removing the card)
		if (cards[i].a > v) {
			v = cards[i].a;
			ans.push_back(cards[i].index);
		}
	}

	// why this sort is based on the index?
	sort(ans.begin(), ans.end());

	const int m = (int)ans.size();
	cout << m << endl;
	for (int i=0; i<m; i++) {
		cout << ans[i] + 1;
		if (i == m-1) {
			cout << endl;
		} else {
			cout << ' ';
		}
	}
	
	return 0;
}