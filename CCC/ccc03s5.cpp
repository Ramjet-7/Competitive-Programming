// Problem: https://dmoj.ca/problem/ccc03s5
#include <bits/stdc++.h>
using namespace std;
const int MXN = 10001;
int c,r,d, parent[MXN], sizes[MXN], ans[MXN];
vector<pair<int,int>> adj[MXN];
bool vis[MXN];
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
	if (vis[s]) return;
	vis[s]=true;
	for (pair<int,int> u : adj[s]){
		int node = u.first;
		int weight = u.second;
		if (!vis[node]){
			ans[node]=min(ans[s], weight);
			dfs(node);
		} 
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<Edge> edges, mst;
	cin >> c >> r >> d;
	int x,y,w,ds;
	for (int i = 1; i <= c; i++){
		sizes[i]=1;
		parent[i]=i;
	}
	for (int i = 0; i < r; i++){
		cin >> x >> y >> w;
		edges.push_back({x,y,w});
		edges.push_back({y,x,w});
	}
	sort(edges.begin(), edges.end());
	for (Edge e : edges){
		//cout << e.u << ' ' << e.v << ' ' << e.weight << '\n';
		if (Find(e.u)!=Find(e.v)){
			mst.push_back(e);
			Union(e.u, e.v);
			adj[e.u].push_back({e.v, e.weight});
			adj[e.v].push_back({e.u, e.weight});
		}
	}
	//cout << '\n';
	ans[1]=INT_MAX-1;
	dfs(1);
	int result=INT_MAX-1;
	while (d--){
		cin >> ds;
		//cout << ans[ds] << '\n';
		result=min(result, ans[ds]);
	}
	cout << result << '\n';
}
