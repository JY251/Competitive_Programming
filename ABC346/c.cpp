#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<bool> appeared(K+1, false);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		appeared[a] = true;
	}
	
	int sum = 0;
	for (int i = 1; i <= K; i++) {
		if (!appeared[i]) {
			sum += i;
		}
	}

	cout << sum << endl;
	return 0;
}