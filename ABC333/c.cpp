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

unsigned long long largestTriangular(unsigned long long N, unsigned long long triangular_last_i) {
	unsigned long long sum = 0;
	unsigned long long i = triangular_last_i;
	unsigned long long j = 0;

	// cout << "triangular_last_i: " << triangular_last_i << endl;
	// cout << "N: " << N << endl;

	while ((sum=sum+i) < N) {
		i--;
		j++;
	}

	// cout << "j: " << j+1 << " Repunit: " << NthRepunit(j+1) << endl;
	// cout << "remain: " << N - (sum-(i+1)) << " Repunit: " << NthRepunit(N - (sum-(i+1)) - 1) << endl;
	// cout << "Nth-repute: " << NthRepunit(triangular_last_i) << endl;
	// cout << "Nth-repute: " << NthRepunit(triangular_last_i) << endl;

	unsigned long long ans = NthRepunit(triangular_last_i) + NthRepunit(j+1) + NthRepunit(N - (sum-(i+1)) - 1);
	
	// cout << "ans: " << ans << endl;

	// return i;
	return ans;
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
		// cout << "ans2 " << largestTriangular(N - old_sum, i-1) << endl;
		// return 3*NthRepunit(i-2) + pow(10, i-2) * (N - old_sum);
		return largestTriangular(N - old_sum, i-1);
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