#include <iostream>
#include <vector>

using namespace std;

int f(const vector<int>& subsequence, int S) {

	int sum = 0;
	int count = 0;

	for (int element : subsequence) {
		sum += element;
		if (sum > S) {
			count++;
			sum = element;
		}
	}

	count++;

	return count;

	// return subsequence.size();
}

int main() {
	int N, S;
	cin >> N >> S;

	vector<int> A(N);

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	int result = 0;

	for (int l = 0; l < N; l++) {
		for (int r = l; r < N; r++) {
			vector<int> subsequence(A.begin()+l, A.begin()+r+1);
			int f_value = f(subsequence, S);

			// for (size_t j=0; j<subsequence.size(); j++) {
			// 	cout << subsequence[j] << " ";
			// }
			// cout << ": " << f_value << endl;

			result += f_value;
		}
	}

	cout << result << endl;
	return 0;
}