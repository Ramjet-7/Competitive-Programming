// Problem: https://dmoj.ca/problem/ccc13s4
#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e6+1;
vector<int> adj[MXN];
bool vis[MXN], yes=false,no=false;
int n,m,x,y,p,q;
// Sate = 1 is P to Q, state = 2 is Q to P
void dfs(int s){
	if (vis[s]) return;
	vis[s]=true;
	// if (s==p&&state==2){
	// 	no=true;
	// 	return;
	// } else if (s==q&&state==1) {
	// 	yes=true;
	// 	return;
	// }
	for (int u : adj[s]){
		if (!vis[u]){
			dfs(u);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	cin >> p >> q;
	dfs(p);
	if (vis[q]){
		cout << "yes\n";
		return 0;
	} 
	memset(vis, 0, sizeof vis);
	dfs(q);
	if (vis[p]){
		cout << "no\n";
		return 0;
	}
	cout << "unknown\n";
}
