// Problem: https://dmoj.ca/problem/dmopc16c4p5
#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+1;
int parent[MXN], sizes[MXN], minD = INT_MAX-1;
vector<pair<int,int>> adj2[MXN];
vector<int> ans(MXN, INT_MAX-1);
bool visited[MXN];
queue<int> q;
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};
int Find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sizes[a] < sizes[b]) swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}
void dfs(int s){
	if (visited[s]) return;
	visited[s]=true;
	for (auto u : adj2[s]){
		int node = u.first;
		int weight = u.second;
		if (!visited[node]){
			ans[node]=min(ans[s], weight);
			dfs(node);
		} 
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<Edge> adj, mst;
	int n, m, u, v, pi;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> u >> v >> pi;
		adj.push_back({u, v, pi});
		adj.push_back({v, u, pi});
	}
	sort(adj.begin(), adj.end());
	for (int i = 1; i <= n; i++){
		parent[i]=i;
		sizes[i]=1;
	}
	for (Edge e : adj){
		//cout << e.u << ' ' << e.v << ' ' << e.weight << '\n';
		if (Find(e.u) != Find(e.v)){
			mst.push_back(e);
			Union(e.u, e.v);
			adj2[e.u].push_back({e.v, e.weight});
			adj2[e.v].push_back({e.u, e.weight});
		}
	}
	ans[1]=INT_MAX-1;
	dfs(1);
	// for (int i = 1; i <= n; i++){
	// 	cout << "NODE " << i << ": ";
	// 	for (pair<int, int> u : adj2[i]){
	// 		cout << '(' << u.first << ',' << u.second << ") ";
	// 	}
	// 	cout << '\n';
	// }
	cout << "0\n";
	for (int i = 2; i <= n; i++){
		cout << ans[i] << '\n';
	}
}
