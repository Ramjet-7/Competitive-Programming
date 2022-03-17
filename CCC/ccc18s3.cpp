// Problem: https://dmoj.ca/problem/ccc18s3
#include <bits/stdc++.h>
using namespace std;
char grid[100][100];
bool watched[100][100], poss=true; // poss checks if spawn point is within camera. if poss==0, all values = -1
const int MAX = 100*100;
set<int> adj[MAX];
queue<int> q;
bool used[MAX], visited[MAX];
int d[MAX], n, m, s;
map<int, int> endpoint;
void add_edge(int u, int v){adj[u].insert(v);}
void camsearch(int row, int col){
	int cnt = col;
	while (grid[row][cnt] != 'W'){
		if (grid[row][cnt] == '.') watched[row][cnt] = true;
		if (grid[row][cnt] == 'S'){
			poss = false;
			return;
		}
		cnt++;
	}
	cnt = col;
	while (grid[row][cnt] != 'W'){
		if (grid[row][cnt] == '.')watched[row][cnt] = true;
		if (grid[row][cnt] == 'S'){
			poss = false;
			return;
		}		
		cnt--;
	}
	cnt = row;
	while (grid[cnt][col] != 'W'){
		if (grid[cnt][col] == '.')watched[cnt][col] = true;
		if (grid[cnt][col] == 'S'){
			poss = false;
			return;
		}		
		cnt--;
	}
	cnt=row;
	while (grid[cnt][col] != 'W'){
		if (grid[cnt][col] == '.')watched[cnt][col] = true;
		if (grid[cnt][col] == 'S'){
			poss = false;
			return;
		}		
		cnt++;
	}
}
int processConveyor(int i, int j, bool arr[]){
	if (grid[i][j]=='L' && !arr[i*m+j]){
		arr[i*m+j]=true;
		return processConveyor(i, j-1, arr);
	} else if (grid[i][j]=='R'&& !arr[i*m+j]){
		arr[i*m+j]=true;
		return processConveyor(i, j+1, arr);
	} else if (grid[i][j]=='U'&& !arr[i*m+j]){
		arr[i*m+j]=true;
		return processConveyor(i-1, j, arr);
	} else if (grid[i][j] == 'D'&& !arr[i*m+j]){
		arr[i*m+j]=true;
		return processConveyor(i+1, j, arr);
	}
	else {
		return i*m+j;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'W' || grid[i][j] == 'C')watched[i][j] = true;
			if (grid[i][j] == 'S') s = i*m+j;
		}
	}
	// Find all Camera's, and find all empy cells that are watched by cameras
	for (int r = 1; r < n-1; r++){
		for (int c = 1; c < m-1; c++){
			if (grid[r][c] == 'C') camsearch(r, c);
		}
	}
	//Construct Adj List
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 'R' || grid[i][j]=='L'|| grid[i][j]=='D'|| grid[i][j]=='U'){
				fill_n(visited, MAX, false);
				int end = processConveyor(i, j, visited);
				if (!watched[end/m][end%m])endpoint[i*m+j]=end;
			}
		}
	}
	for (int i = 1; i < n-1; i++){
		for (int j = 1; j < m-1;j++){
			if ((grid[i][j] == 'S' || grid[i][j]=='.')&&!watched[i][j]){
				if (grid[i][j+1]=='.' && !watched[i][j+1]){
					add_edge(i*m+j, i*m+j+1);add_edge(i*m+j+1, i*m+j);
				} if (grid[i][j-1]=='.' && !watched[i][j-1]){
					add_edge(i*m+j, i*m+j-1);add_edge(i*m+j-1, i*m+j);
				} if (grid[i+1][j]=='.' && !watched[i+1][j]){
					add_edge(i*m+j, (i+1)*m+j);add_edge((i+1)*m+j, i*m+j);					
				} if (grid[i-1][j]=='.' && !watched[i-1][j]){
					add_edge(i*m+j, (i-1)*m+j);add_edge((i-1)*m+j, i*m+j);					
				} if (grid[i][j+1] != '.' && grid[i][j+1]!='S' && !watched[i][j+1]){
					add_edge(i*m+j, endpoint[i*m+j+1]);
				} if (grid[i][j-1] != '.' && grid[i][j-1]!='S' && !watched[i][j-1]){
					add_edge(i*m+j, endpoint[i*m+j-1]);
				} if (grid[i+1][j] != '.' && grid[i+1][j]!='S' && !watched[i+1][j]){
					add_edge(i*m+j, endpoint[(i+1)*m+j]);
				} if (grid[i-1][j] != '.' && grid[i-1][j]!='S' && !watched[i-1][j]){
					add_edge(i*m+j, endpoint[(i-1)*m+j]);
				}
			}
		}
	}
	//BFS
	q.push(s);
	used[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j]=='.' && poss){
				if (d[i*m+j]==0) cout << "-1\n";
				else cout << d[i*m+j] << '\n';
			} else if (grid[i][j]=='.' && !poss){
				cout << "-1\n";
			}
		}
	}
}
