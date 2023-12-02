#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, S, M, L;
	cin >> N >> S >> M >> L;

	int minCostS = (N / 6 + (N % 6 != 0)) * S;
	int minCostM = (N / 8 + (N % 8 != 0)) * M;
	int minCostL = (N / 12 + (N % 12 != 0)) * L;

	int result = min({minCostS, minCostM, minCostL});

	cout << minCostS << " " << minCostM << " " << minCostL << endl;

	cout << result << endl;
	

	return 0;
}