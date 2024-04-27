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
		cout << "column num (after push " << i << "-th element): " << column.size() << endl;
		for (int j = 0; j < column.size(); j++) {
			cout << column[j] << " ";
		}
		cout << endl;
		while (!(column.size() <= 1) && (column[column.size()-1] == column[column.size()-2])) {
				int a = column[column.size()-1];
				// int b = column[column.size()-2];
				column.pop_back();
				column.pop_back();
				// 2^a + 2^b = 2^(a+1)
				column.push_back(a+1);
				for (int j = 0; j < column.size(); j++) {
					cout << column[j] << " ";
				}
				cout << endl;

		}
		cout << "column num (after pop if necessary): " << column.size() << endl;
	}

	cout << column.size() << endl;
	return 0;
}