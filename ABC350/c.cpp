#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> swap_pairs;

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
	int pivot = vec[low];
	// int pivot = min(vec[low], vec[low+1]);
	int i = low, j = high;

	while(i < j) {
		while(vec[i] < pivot) i++;
		while(vec[j] >= pivot) j--;

		// if (i >= j) return i;
		swap_in_vec(vec, i, j);
		swap_pairs.push_back(make_pair(i, j));
		i++;
		j--;
	}

	return i;
}

// // the following is O(n) for partitioning
// int partition(vector<int>& vec, int low, int high) {
// 	int pivot = vec[high];
// 	int i = low - 1; // iは現時点で最後にpivotより小さい要素がある場所を表す (iより左（iも含む）はpivotより小さい)

// 	// loop shoulbe be till j = high - 1 (high - 2ではだめ。)
// 	// 3 4 1 2 5のような配列だったら、high - 2だと、3 4 1 5 2のようになってしまう
// 	for (int j = low; j < high; j++) { // jは現時点で見ている要素の場所を表す
// 		if (vec[j] < pivot) {
// 			// もしvec[j]がpivotより小さいならば、vec[j]をiの位置に持っていき、iよりも左（iも含む）にpivotより小さい要素がある状態にする
// 			i++;
// 			swap_in_vec(vec, i, j);
// 			if (i != j) {
// 				swap_pairs.push_back(make_pair(i, j));
// 			}
// 		}
// 	}
// 	swap_in_vec(vec, i+1, high);
// 	if (i+1 != high) {
// 		swap_pairs.push_back(make_pair(i+1, high));
// 	}
// 	return i+1;
// }

void quick_sort(vector<int>& vec, int low, int high) {
	printf("low: %d, high: %d\n", low, high);

	// if the following condition does not work because array like (2, 1) should be sorted but low < high - 1 is not satisfied (low = 0, high = 1)
	// if (low < high - 1) { // low < high is not enough: In case of low = 3, high = 4, you don't need to divide to do quick_sort
	if (low < high) {
		int pivotIndex = partition(vec, low, high);
		printf("partitioned at %d\n", pivotIndex);
		print_vec(vec, high+1);
		quick_sort(vec, low, pivotIndex-1);
		quick_sort(vec, pivotIndex, high);
	}
}

int main() {
	int N; // 1 <= N <= 10^5 (N: -2^31 ~ 2^31 = -2,147,483,648 ~ 2,147,483,647)
	cin >> N;

	swap_pairs = vector<pair<int, int>>(0);

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	quick_sort(A, 0, N-1);

	// print_vec(A, N);
	cout << swap_pairs.size() << endl;
	for (size_t i = 0; i < swap_pairs.size(); i++) {
		cout << swap_pairs[i].first + 1 << " " << swap_pairs[i].second + 1 << endl;
	}

	return 0;
}