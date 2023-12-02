#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// example: 99 600 800 1200

using namespace std;

int main() {
	int N, S, M, L;
	cin >> N >> S >> M >> L;

	vector<vector<int>> twoDimVector(N+1, vector<int>(3, INT_MAX));
	// not do this will cause answer to be INT_MAX
	twoDimVector[0][0] = 0;

	// N can be cut: 0 can be cut; only remains even (except for N)
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=2; j++) {
			if (j==0) {
				twoDimVector[i][j] = ((i / 6) + (i % 6 != 0))*S;
			} else if (j==1) {
				// for loopで、
				for (int k=0; k<i; k++) {
					twoDimVector[i][j] = min(twoDimVector[i][j], twoDimVector[k][j-1] + ((i-k)/8 + ((i-k)%8 != 0))*M);
				}
				twoDimVector[i][j] = min(twoDimVector[i][j], twoDimVector[i][j-1]);
			} else {
				for (int k=0; k<i; k++) {
					// cout << "start" << endl;
					// cout << twoDimVector[k][j-1] + (i-k)/12 + ((i-k)%12 != 0) << endl;
					twoDimVector[i][j] = min(twoDimVector[i][j], twoDimVector[k][j-1] + ((i-k)/12 + ((i-k)%12 != 0))*L);
				}
				twoDimVector[i][j] = min(twoDimVector[i][j], twoDimVector[i][j-1]);
			}
		}
	}

	// for (int j=0; j<3; j++) {
	// 	for (int i=0; i<=N; i++) {
	// 		cout << twoDimVector[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << twoDimVector[N][2] << endl;
	return 0;
}