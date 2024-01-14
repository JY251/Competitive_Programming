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
		for (int i=0; i<=(N+1)/2; i++) {
			if (A[i] > i+1 && A[N-i-1] > i+1) {
				ans = N;
				break;
			}
		}
		ans = N;
	}

	cout << ans << endl;

	return 0;
}