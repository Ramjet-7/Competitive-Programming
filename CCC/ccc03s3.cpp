// Problem: https://dmoj.ca/problem/ccc03s3
#include <bits/stdc++.h>
using namespace std;
int flooring, r, c;
char grid[25][25];
vector<int> adj[625];
bool visited[625];
vector<int> sizes;
int size = 0;
int dfs(int s){
	if (visited[s]) return 0;
	visited[s] = true;
	size++;
	for (auto u : adj[s]) {
		dfs(u);
	}
	return size;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> flooring >> r >> c;
	int R = r, cnt = 0, row = 0;
	string s, prev_row;
	while (R--){
		cin >> s;
		for (int i = 0; i < c; i++) grid[row][i] = s[i];
		// Construct Graph
		for (int i = 0; i < c; i++){
			if (i < c-1 && s[i] == '.' && s[i+1] == '.'){
				adj[i+cnt].push_back(i+1+cnt);
				adj[i+1+cnt].push_back(i+cnt);
			}
			if (row >= 1) {
				if (s[i] == '.' && prev_row[i] == '.') {
					adj[i+cnt].push_back(i+cnt-c);
					adj[i+cnt-c].push_back(i+cnt);
				}
			}
		}
		prev_row = s;
		cnt+=c;
		row++;
	}
	// Print Adjacency List:
	// for (int i = 0; i < r; i++){
	// 	for (int j = 0; j < c; j++){
	// 		if (grid[i][j] == '.'){
	// 			for (int element : adj[j+i*c]) cout << element << " ";
	// 			cout << "\n";
	// 		}
	// 	}
	// }
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c;j++){
			if (grid[i][j] == '.' && !visited[i*c+j]) {
				size = 0;
				sizes.push_back(dfs(i*c+j));
			}
		}
	}
	int num = 0;
	sort(sizes.begin(), sizes.end(), greater<int>());
    for (auto siz : sizes){
		if (flooring-siz >= 0) {
			flooring -= siz;
			num++;
		} else {
			//flooring = siz - flooring;
			break;
		}
	}
	if (num == 1){
		cout << num << " room, " << flooring << " square metre(s) left over";
	} else {
		cout << num << " rooms, " << flooring << " square metre(s) left over";

	}
}
