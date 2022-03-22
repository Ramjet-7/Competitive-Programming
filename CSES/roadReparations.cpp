#include <bits/stdc++.h>
using namespace std;
const int MXN = 100001;
int parent[MXN], sizes[MXN];
bool vis[MXN];
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<Edge> edges;
	int n,m,x,y,w,nodes=0;
	long long ans=0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		sizes[i]=1;
		parent[i]=i;
	}
	for (int i = 0; i < m; i++){
		cin >> x >> y >> w;
		edges.push_back({x,y,w});
		edges.push_back({y,x,w});
	}
	sort(edges.begin(), edges.end());
	for (Edge e : edges){
		if (Find(e.u)!=Find(e.v)){
			Union(e.u, e.v);
			ans+=e.weight;
			nodes++;
		}
	}
	if (nodes+1==n)cout << ans << '\n';
	else cout << "IMPOSSIBLE\n";
}