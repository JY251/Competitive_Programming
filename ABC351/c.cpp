#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> column;
	for (int i = 1; i <= N; i++) {
		// i is 1-indexed; A is 0-indexed
		column.push_back(A[i-1]);
		while (!(column.size() <= 1) && (column[column.size()-1] == column[column.size()-2])) {
				int a = column[column.size()-1];
				// int b = column[column.size()-2];
				column.pop_back();
				column.pop_back();
				// 2^a + 2^b = 2^(a+1)
				column.push_back(a+1);
		}
	}

	cout << column.size() << endl;
	return 0;
}