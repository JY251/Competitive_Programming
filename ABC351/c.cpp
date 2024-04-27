#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		A[i] = 0;
	}

	vector<int> column;
	for (int i = 1; i <= N; i++) {
		// i is 1-indexed; A is 0-indexed
		column.push_back(A[i-1]);
		if (!(column.size() <= 1)) {
			if (column[column.size()-1] == column[column.size()-2]) {
				int a = column[column.size()-1];
				int b = column[column.size()-2];
				column.pop_back();
				column.pop_back();
				column.push_back(a+b);
			}
		}
	}

	cout << column.size() << endl;
	return 0;
}