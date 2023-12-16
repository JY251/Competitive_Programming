#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

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


double distance(pair<double, double> p1, pair<double, double> p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

pair<double, double> getCoordinates(Vertex v) {
	switch(v) {
		case A: return {0, 0};
		case B: return {1, 0};
		case C: return {cos(2*M_PI/5), sin(2*M_PI/5)};
		case D: return {cos(4*M_PI/5), sin(4*M_PI/5)};
		case E: return {cos(6*M_PI/5), sin(6*M_PI/5)};
		default: return {0, 0};
	}
}


bool areSegmentsEqual(Vertex s1, Vertex s2, Vertex t1, Vertex t2) {
	double lengthS = distance(getCoordinates(s1), getCoordinates(s2));
	double lengthT = distance(getCoordinates(t1), getCoordinates(t2));

	return fabs(lengthS - lengthT) < 1e-100;
}



int main() {
	string s, t;
	cin >> s >> t;
	string s1, s2, t1, t2;

	s1 = s.substr(0, 1);
	s2 = s.substr(1, 1);
	t1 = t.substr(0, 1);
	t2 = t.substr(1, 1);

	// cout << s << " " << t << endl;
	// cout << s1 << " " << s2 << " " << t1 << " " << t2 << endl;

	if (areSegmentsEqual(stringToVertex(s1), stringToVertex(s2), stringToVertex(t1), stringToVertex(t2))) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}


	return 0;
}