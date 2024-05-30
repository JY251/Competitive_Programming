// Copied the following solution:
// https://atcoder.jp/contests/adt_medium_20240522_3/editorial/4878
#include <bits/stdc++.h>
using namespace std;

// Q. What does it mean by `200010`?
// 2N-2 vertices at most: N=02*10^5 => ?
vector<int>e[200010];
bool flag[200010];
// What does it mean by `deque`?
// doouble-ended queue: insert and delete from both the beginning and the end
deque<int> deq;
bool stop;

void dfs(int k, int to) {
	if (!stop)deq.push_back(k);
	if (k==to)stop=true;
	flag[k]=true;
	int sz=e[k].size();
	for (int i=0;i<sz;i++) {
		if(!flag[e[k][i]])dfs(e[k][i], to);
	}
	// if you can reach to the destination, stop will be `true` by some `dfs(e[k][i], to)` in the above loop
	// Therefore, `stop=false` means there are no way to reach to the destination from the current vertex: remove the current vertex from the path (deq)
	if(!stop)deq.pop_back();
	return;
}

int main() {
	int n, x, y;
	int u, v;

	cin >> n >> x >> y;
	for (int i=0; i<n-1; i++) {
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1;i<=n;i++)flag[i]=false;
	stop=false;
	dfs(x, y);

	while(!deq.empty()){
		cout<<deq.front();
		deq.pop_front();
		if(deq.empty())cout<<endl;
		else cout<<" ";
	}
	return 0;
}
