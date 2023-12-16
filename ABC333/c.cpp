#include <iostream>
#include <cmath>

using namespace std;

// unsigned long long getNthRepunitSum(int n) {
// 	int digits = n;

// 	unsigned long long sum = 0;
// 	for (int i=0; i<digits; i++) {
// 		sum *= 10;
// 		sum += 1;
// 	}

// 	unsigned long long repunitSum = 0;
// 	for (int i=0; i<3; i++) {
// 		repunitSum *= 10;

// 	}


// }

unsigned long long Triangular(unsigned long long N) {
	return N*(N+1)/2;
}

unsigned long long NthRepunit(unsigned long long n) {
	unsigned long long sum = 0;
	for (unsigned long long i=0; i<n; i++) {
		sum *= 10;
		sum += 1;
	}
	return sum;
}

unsigned long long largetsTriangular(unsigned long long N, unsigned long long triangular_last_i) {
	unsigned long long sum = 0;
	unsigned long long i = triangular_last_i;

	while ((sum=sum+i) <= N) {
		i--;
	}

	// return i;
	return sum;
}


unsigned long long largestSumOfTriangulerNumber(unsigned long long N) {
	// (n^2 + n) / 2 = N
	
	// long long  discriminant = 1 + 8*N;

	unsigned long long sum = 0;
	unsigned long long old_sum = 0;
	unsigned long long i = 0;
	while (sum <= N) {
		// sum += i;
		old_sum = sum;
		sum += Triangular(i);
		i++;
	}

	if (old_sum == N) {
		return 3*NthRepunit(i-2);
	} else {
		// cout << "remain: " << N - old_sum << endl;
		// cout << "next sum of tri.: " << Triangular(i-1) << "/" << i-1 << "th" << endl;
		// cout << pow(10, i-1) << endl;
		return 3*NthRepunit(i-2) + pow(10, i-2) * (N - old_sum);
	}
	return old_sum;
	// return i;
}



int main() {
	unsigned long long N;
	cin >> N;
	unsigned long long largetsTriangular = largestSumOfTriangulerNumber(N);
	cout << largetsTriangular << endl;
	return 0;
}