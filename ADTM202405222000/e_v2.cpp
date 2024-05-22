#include <bits/stdc++.h>
using namespace std;

struct Node {
	int index;
	vector<Node*> children;
};

void buildTree(const vector<pair<int, int>>& edges, Node* root) {
	unordered_map<int, Node*> nodes;

	for (const auto& edge: edges) {
		int node1 = edge.first, node2 = edge.second;
		if (!nodes.count(node1)) {
			nodes[node1] = new Node{node1, {}};
		}
		if (!nodes.count(node2)) {
			nodes[node2] = new Node{node2, {}};
		}
	}

	for (const auto& edge: edges) {
		nodes[edge.first]->children.push_back(nodes[edge.second]);
		nodes[edge.second]->children.push_back(nodes[edge.first]);
	}

	root = nodes.begin()->second;
}

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<pair<int, int>> edges(n-1);
	for (int i=0; i<n-1; i++) {
		cin >> edges[i].first >> edges[i].second;
	}

	Node* root = nullptr;
	buildTree(edges, root);

	vector<int> path_from_x, path_from_y;
	
}