#include <iostream>
#include <map>

using namespace std;

// enum Vertex {"A", "B", "C", "D", "E"};
enum Vertex {A, B, C, D, E};

Vertex stringToVertex(const string& str) {
	static const map<string, Vertex> vertexmap = {
		{"A", A},
		{"B", B},
		{"C", C},
		{"D", D},
		{"E", E}
	};

	auto it = vertexmap.find(str);
	if (it != vertexmap.end()) {
		return it->second;
	} else {
		cerr << "Error: " << str << " is not a vertex." << endl;
		exit(1);
	}
}


double distance(pair<double, double> p1, parir<double, double> p2) {
	// return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

// pair<double, double> getCoordinates(Vertex v) {
// 	switch(v) {
// 		case A: return {0, 0};
// 		case B: return {1, 0};
// 		case C: return {cos(2*M_PI/5), sin(2*M_PI/5)};
// 		case D: return {cos(4*M_PI/5), sin(4*M_PI/5)};
// 		case E: return {cos(6*M_PI/5), sin(6*M_PI/5)};
// 		default: return {0, 0};
// 	}
// }


bool areSegmentsEqual(Vertex s1, Vertex s2, Vertex t1, Vertex t2) {
	// double lengthS = distance(getCoordinates(s1), getCoordinates(s2));
	// double lengthT = distance(getCoordinates(t1), getCoordinates(t2));

	// return fabs(lengthS - lengthT) < 1e-100;
	return 0;
}

int main() {
	Vertex s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;


	// if (areSegmentsEqual(s1, s2, t1, t2)) {
	// 	cout << "Yes" << endl;
	// } else {
	// 	cout << "No" << endl;
	// }

	return 0;
}