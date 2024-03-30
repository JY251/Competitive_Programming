#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	vector<int> D(N);
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}

	for (int i = 0; i < A+B; i++) {
		bool is_all_holiday = false;
		for (int j = 0; j < N; j++) {
			is_all_holiday = true;
			if ((i + D[j]) % (A+B) >= A) {
				is_all_holiday = false;
			}
		}
		if (is_all_holiday == true) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}