// Problem: https://dmoj.ca/problem/bts18p4
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 100000;
vector<ll> strength(N+1), nodes, adj[N+1];
vector<bool> vis(N+1), vis2(N+1);
int maxD=0, maxNode=0, ans = 0;
void dfs (int node, int d) {
	vis[node] = true, vis2[node]=true;;
	if (d > maxD)maxD = d, maxNode = node;
	for (int u : adj[node]){
		if (!vis2[u]) dfs(u, d+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; ll yi;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> yi;
		strength[i+1]=yi;
		if (ll(sqrt(4*yi+1))*ll(sqrt(4*yi+1))==4*yi+1 && (4*yi+1)%2!=0){
			nodes.push_back(i+1);
		}
	}
	// for (int i : strength) cout << i << ' ';
	// cout << '\n';
	// for (int i : nodes) cout << i << ' ';
	// cout << '\n';
	int a,b;
	for (int i = 0; i < n-1; i++){
		cin >> a >> b;
		if (ll(sqrt(4*strength[a]+1))*ll(sqrt(4*strength[a]+1))==4*strength[a]+1 && (4*strength[a]+1)%2!=0){
			if (ll(sqrt(4*strength[b]+1))*ll(sqrt(4*strength[b]+1))==4*strength[b]+1 && (4*strength[b]+1)%2!=0){
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
	}
	// for (int i = 1; i <= n; i++){
	// 	cout << "NODE " << i << ": ";
	// 	for (int v : adj[i]){
	// 		cout << v << ' ';
	// 	}
	// 	cout << '\n';
	// }
	for (int i : nodes){
		if (!vis[i]) {
			maxD = -1;  
			dfs(i, 0);
			maxD=-1;
			fill_n(vis2.begin(), n+1, false);
			dfs(maxNode, 0);
			ans = max(ans, maxD+1);
		}
	}
	cout << ans;
}
