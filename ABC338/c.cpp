#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> Q(N), A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> Q[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	int max_people = 0;
	for (int i = 0; i < N; i++) {
		int people = min(A[i], B[i]);
		max_people = max(max_people, people);
	}

	cout << max_people << endl;

	return 0;
}