// Problem: https://dmoj.ca/problem/ccc01s3
// Due to low restrictions, could've done brute force
// deleting edges and dfs. Instead i over thought and did
// cut edges :(
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[26];
vector<pair<int, int>> bridges;
bool visited[26];
int in[26], low[26];
int timer, ans;
bool bridgefind = true;
void dfs(int node, int par){
	visited[node] = true;
	in[node] = low[node] = timer;
	timer++;
	for (int descent : adj[node]){
		if (descent == par) continue;
		if (visited[descent]){
			low[node] = min(low[node], in[descent]);
		} else {
			dfs(descent, node);
			if (low[descent] > in[node]) {
				//cout << char(node+65) << " - " << char(descent+65) << " is a bridge\n";
				//cout << char(descent+65) << char(node+65) << "\n";
				bridges.push_back({descent, node});
				ans++;
			}
			low[node] = min(low[node], low[descent]);
		}
	}
}
void dfs(int s, pair<int, int> bridge){
	if (visited[s]) return;
	visited[s] = true;
	if (s == 1){
		bridges.erase(remove(bridges.begin(), bridges.end(), bridge), bridges.end());
		return;
	}
	for (int u : adj[s]) {
		dfs(u, bridge);
	}
}
void remove_edge(int a, int b){
	adj[a].erase(remove(adj[a].begin(), adj[a].end(), b), adj[a].end());
	adj[b].erase(remove(adj[b].begin(), adj[b].end(), a), adj[b].end());
}
void add_edge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	while (s != "**"){
		add_edge(int(s[0])-65, int(s[1])-65);
		add_edge(int(s[1])-65, int(s[0])-65);
		cin >> s;
	}
	// PRINT ADJ List
	// for (auto vec : adj){
	// 	for (int node : vec){
	// 		cout << node << " ";
	// 	}
	// 	cout << "\n";
	// }
	dfs(0, -1);
	bridgefind = false;
	for (auto bridge : bridges){
		fill_n(visited, 26, false);
		remove_edge(bridge.first, bridge.second);
		dfs(0, bridge);
		add_edge(bridge.first, bridge.second);
	}
	for (auto bridge : bridges){
		cout << char(bridge.first+65) << char(bridge.second+65) << "\n";
	}
	cout << "There are " << bridges.size() << " disconnecting roads.\n";
}
