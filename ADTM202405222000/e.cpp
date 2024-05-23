#include <bits/stdc++.h>
using namespace std;

typedef struct tree {
	int node;
	struct tree *child;
	struct tree *parent;
} Tree;

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> u(n), v(n);
	for (int i=0; i<n; i++) {
		cin >> u[i] >> v[i];
	}

	Tree *root = new Tree;	
	for (int i=0; i<n-1; i++) {
		root->node = u[i];
	}


	return 0;
}