// Problem: https://dmoj.ca/problem/graph1
#include <vector>
#include <iostream>
using namespace std;
const int MXN = 10001;
vector<int> adj[MXN];
bool vis[MXN];
void dfs(int s){
	vis[s]=true;
	for (int u : adj[s]) if (!vis[u]) dfs(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int x,y;
	cin >> x >> y;
	dfs(x);
	if (vis[y]) cout << "1\n";
	else cout << "0\n";
}