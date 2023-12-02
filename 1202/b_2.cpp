#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, S, M, L;
	cin >> N >> S >> M >> L;

	double costPerEggS = static_cast<double>(S) / 6;
	double costPerEggM = static_cast<double>(M) / 8;
	double costPerEggL = static_cast<double>(L) / 12;

	double minCostPerEgg = min({costPerEggS, costPerEggM, costPerEggL});





	int minCostS = (N / 6 + (N % 6 != 0)) * S;
	int minCostM = (N / 8 + (N % 8 != 0)) * M;
	int minCostL = (N / 12 + (N % 12 != 0)) * L;

	int result = min({minCostS, minCostM, minCostL});

	cout << result << endl;
	

	return 0;
}