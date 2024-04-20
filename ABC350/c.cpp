#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec, int n) {
	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

void swap_in_vec(vector<int>& vec, int i, int j) {
	int tmp = vec[i];
	vec[i] = vec[j];
	vec[j] = tmp;
}

int partition(vector<int>& vec, int low, int high) {
	int pivot = vec[high];
	int i = low - 1; // iは現時点で最後にpivotより小さい要素がある場所を表す (iより左（iも含む）はpivotより小さい)

	// loop shoulbe be till j = high - 1 (high - 2ではだめ。)
	// 3 4 1 2 5のような配列だったら、high - 2だと、3 4 1 5 2のようになってしまう
	for (int j = low; j < high; j++) { // jは現時点で見ている要素の場所を表す
		if (vec[j] < pivot) {
			// もしvec[j]がpivotより小さいならば、vec[j]をiの位置に持っていき、iよりも左（iも含む）にpivotより小さい要素がある状態にする
			i++;
			swap_in_vec(vec, i, j);
		}
	}
	swap_in_vec(vec, i+1, high);
	return i+1;
}

void quick_sort(vector<int>& vec, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(vec, low, high);
		// print_vec(vec, high+1);
		quick_sort(vec, low, pivotIndex-1);
		quick_sort(vec, pivotIndex+1, high);
	}
}

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	quick_sort(A, 0, N-1);

	print_vec(A, N);

	return 0;
}