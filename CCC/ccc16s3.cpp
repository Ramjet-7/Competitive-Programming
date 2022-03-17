// Problem: https://dmoj.ca/problem/ccc16s3
#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+1;
int n,m;
vector<int> adj[MXN];
bool vis[MXN], valid[MXN], diameter[MXN]; 
pair<int, int> edges[MXN];
bool found=false,final=false;
int root, maxD=0, maxNode=0, ans = -1, subSize[MXN], parent[MXN];
// DFS for finding size of subtrees (not part of tree diameter)
int sizes=0;
void dfs(int s){
	if (vis[s]) return;
	vis[s]=true;
	sizes++;
	for (int u : adj[s]){
		if (!diameter[u] && !vis[u]){
			dfs(u);
		}
	}
}
int dfs1(int node) {
	vis[node] = 1;
	int curr = 1;
	for(int child : adj[node]){
		if(vis[child] == 0) {
			curr+=dfs1(child);
			if (!valid[child]) curr--;
		}	
	}
	return subSize[node] = curr;
}
void dfs(int node, int d) {
	vis[node] = true;
	if (d > maxD){
		maxD = d, maxNode = node;
	}
	for (int u : adj[node]){
		if (!vis[u]) {
			dfs(u, d+1);
			if (final)parent[u]=node;
		}
	}
}
// OBSERVATION: min time needed is tree diameter + the size of subtrees
// not part of the diameter * 2. Supposed a subtree of size 7 is attatched to a 
// node part of the diaemter. It would take 14 mins to travel that subtree and
// back to the initial path (tree diameter)
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> root;
	valid[root]=true;
	for (int i = 0; i < m-1; i++){
		int pho;
		cin >> pho;
		valid[pho]=true;
	}
	for (int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i].first=u;
		edges[i].second=v;
	}
	dfs1(root);
	for (int i = 0; i <= n; i++) adj[i].clear();
	for (int i= 0; i < n; i++){
		if (subSize[i] > 1) valid[i]=true;
	}
	// Valid = needed for traversal
	for (int i = 0; i <n; i++){
		int x=edges[i].first, y=edges[i].second;
		if (valid[x]&&valid[y]){
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	// Finding Diameter
	maxD = -1;  
	memset(vis, 0, sizeof vis);
	dfs(root, 1);
	maxD=-1;
	memset(vis, 0, sizeof vis);
	final=true;
	int temp=maxNode;
	dfs(maxNode, 1);
	diameter[maxNode]=true;
	ans++;
	while (true){
		diameter[parent[maxNode]]=true;
		maxNode=parent[maxNode];
		ans++;
		if (maxNode==temp) break;
	}
	memset(vis,0,sizeof vis);
	for (int i = 0; i < n; i++){
		if (!vis[i] && !diameter[i] && valid[i]){
			sizes=0;
			dfs(i);
			ans+=2*sizes;
		}
	}
	cout << ans;
}
