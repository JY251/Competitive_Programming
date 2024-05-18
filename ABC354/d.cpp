#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int area_2 = 0;

	for (int i=a; i<c; i++) {
		for (int j=b; j<d; j++) {
			int new_i = i % 4;
			int new_j = j % 2;

			// in C++, -10 % 4 = -2, so you need to add 4 to get the positive remainder (So does %2)
			if (new_i < 0) new_i += 4;
			if (new_j < 0) new_j += 2;

			// cout << i << " " << j << " (" << new_i << " " << new_j << "): " << area_2 << endl;

			switch(new_i) {
				case 0:
					switch(new_j) {
						case 0:
							area_2+=1*2;
							break;
						case 1:
							area_2+=(int)(0.5*2);
							break;
					}
					break;
				case 1:
					switch(new_j) {
						case 0:
							area_2+=(int)(0.5*2);
							break;
						case 1:
							area_2+=1*2;
							break;
					}
					break;
				case 2:
					switch(new_j) {
						case 0:
							break;
						case 1:
							area_2+=(int)(0.5*2);
							break;
					}
					break;
				case 3:
					switch(new_j) {
						case 0:
							area_2+=(int)(0.5*2);
							break;
						case 1:
							break;
					}
					break;
			}
		}
	}

	cout << area_2 << endl;

	return 0;
}