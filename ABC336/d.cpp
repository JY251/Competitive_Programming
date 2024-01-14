#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPyramidSize(const vector<int> &A) {
	int n = A.size();
	int result = 0;

	for (int i = 0; i < n; ++i) {
		int leftSize = i + 1;
		int rightSize = n - i - 1;

		int minSize = min(leftSize, rightSize);
		result = max(result, minSize);
	}

	return result * 2 - 1;
}


int main() {
	
}