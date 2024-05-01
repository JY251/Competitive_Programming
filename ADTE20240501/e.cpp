#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int from, to;	
};

int main() {
	int N;
	cin >> N;

	vector<vector<Edge>> graph(N+1); // vector of node: each node stores connected edges

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back({a, b});
		graph[b].push_back({b, a});
	}

	queue<int> q;
	vector<int> dist(N+1, -1);
	dist[1] = 0;
	q.pop();

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for (const Edge& e: graph[cur]) {
			int next = e.to;
			if (dist[next] == -1) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= N; i++) {
		res = max(res, dist[i]);
	}

	cout << res << endl;

	return 0;
}