#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec, int n) {
	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main() {
	int N, Q;
	cin >> N >> Q;

	vector<int> T(Q);
	vector<int> ExistTooth(N, 1);

	for (int i = 0; i < Q; i++) {
		cin >> T[i];
	}

	for (int i = 0; i < Q; i++) {
		if (ExistTooth[T[i]-1] == 1) {
			ExistTooth[T[i]-1] = 0;
		} else {
			ExistTooth[T[i]-1] = 1;
		}
		// print_vec(ExistTooth, N);
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		count += ExistTooth[i];
	}

	cout << count << endl;

	return 0;
}