#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	// Each 4x2 rectangles have 4 area => 4*2 = 8
	// there are `((c-a)/4) * ((d-b)/2)` number of 4x2 rectangles
	int area_2 = 8 * ((c-a)/4) * ((d-b)/2);
	// cout << "4x2: " << area_2 << endl;

	// There are some 1x2 rectangles left in the left/right side of the 4x2 rectangles
	for (int j=(b%2==0)?b:b+1; j+2<c; j+=2) {
		for (int i=a; i<a+(c-a)%4; i++) {
			int new_i = i % 4;
			// in C++, -10 % 4 = -2, so you need to add 4 to get the positive remainder (So does %2)
			if (new_i < 0) new_i += 4;

			// cout << i << " " << j << " (" << new_i << " " << j << "): " << area_2 << endl;

			switch(new_i) {
				case 0:
					area_2+=3;
					break;
				case 1:
					area_2+=3;
					break;
				case 2:
					area_2+=1;
					break;
				case 3:
					area_2+=1;
					break;
			}
		} 
	}
	// cout << "2x2: " << area_2 << endl;


	// There are still 1 row left in either top or bottom of the filled 4x2 rectangles and 1x2 rectangles
	if ((d-b)%2!=0) {
		for (int i=a; i<c; i++) {
			int j = (b%2)?d:b;
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