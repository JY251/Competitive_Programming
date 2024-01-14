#include <iostream>
#include <vector>
using namespace std;

int main() {
	long N;
	cin >> N;

	vector<long> A(N);
	for (long i = 0; i < N; i++) {
		cin >> A[i];
	}

	long ans;

	if (N % 2 == 0) {
		ans = N-1;
	} else {
		ans = N;
	}

	cout << ans << endl;

	return 0;
}