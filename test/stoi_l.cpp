#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>


using namespace std;

int main() {
	stringstream ss;
	ss << "10737418241073741824"; // this causes overflow
	// ss << "1073741824"; // this works

	int sum = 0;
	sum = stoi(ss.str());
	cout << sum << endl;
	return 0;

	// try {
	// }
}