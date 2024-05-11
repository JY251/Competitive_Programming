#include <fstream>
#include <iostream> // cerr
#include <string>

using namespace std;

int main() {
	cout << "Input the length of the characters:" << endl;
	int n; 
	cin >> n;
	ofstream ofs("d_test.txt");

	if (!ofs.is_open()) {
		cerr << "Failed to open file" << endl;
		return 1;
	}

	// n = 200000;
	ofs << n << endl;
	string one_with_space = "1 ";
	for (int i = 0; i < n; i++) {
		ofs << one_with_space;
	}

	ofs.close();
	return 0;
}