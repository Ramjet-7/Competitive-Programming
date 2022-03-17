// Problem: https://dmoj.ca/problem/sssp
#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX-1;
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>> q;
vector<int> d(1001, INF);
bool vis[1001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	// Start Dijkstra at Node 1
	d[1]=0;
	q.push({0, 1});
	while (!q.empty()){
		int a = q.top().second;
		q.pop();
		if (vis[a]) continue;
		vis[a]=true;
		for (pair<int, int> node : adj[a]){
			int v = node.first;
			int w = node.second;
			if (d[a]+w < d[v]){
				d[v]=d[a]+w;
				q.push({-d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++) d[i]==INF ? cout << "-1\n" : cout << d[i] << '\n';
}
