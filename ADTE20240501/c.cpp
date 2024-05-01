#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N), B(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int count_same_with_pos = 0;
	// int hit = 0;
	int blow = 0;
	unordered_map<int, int> count_a, count_b;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N; i++) {
		count_a[A[i]]++;
		count_b[B[i]]++;
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == B[i]) {
			count_same_with_pos++;
		} else if (count_a[A[i]] > 0 && count_b[A[i]] > 0) { // here should not be count_b[B[i]] > 0
			// the case same char occurs more than once in A does not h appen; So does B
			blow++;
		} 
	}



	cout << count_same_with_pos << endl;
	cout << blow << endl;

	return 0;
}