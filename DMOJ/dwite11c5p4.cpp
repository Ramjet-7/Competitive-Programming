// Problem: https://dmoj.ca/problem/dwite11c5p4
#include <bits/stdc++.h>
using namespace std;
bool block[50][20][20], vis[20][20], hitExt=false;
int n, m, si=0;
void dfs(int r, int c, int z){
	if (vis[r][c]) return;
	vis[r][c]=true;
	si++;
	if (r==0 || r==n-1 || c==0 || c==m-1) hitExt = true;
	if (r > 0 && !block[z][r-1][c]) dfs(r-1, c, z);
	if (r < n-1 && !block[z][r+1][c]) dfs(r+1, c, z);
	if (c > 0 && !block[z][r][c-1]) dfs(r, c-1, z);
	if (c < m-1 && !block[z][r][c+1]) dfs(r, c+1, z);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt=5;
	while (tt--){
		memset(block, 0, sizeof block);
		int grid[20][20], maxh=0, ans=0;
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cin >> grid[i][j];
				maxh=max(maxh, grid[i][j]);
				int temp = grid[i][j];
				while (temp > 0){
					block[temp-1][i][j]=true;
					temp--;
				}
			}
		}
		for (int i = 0; i < maxh; i++){
			memset(vis, 0, sizeof vis); 
			for (int j = 1; j < n-1; j++){
				for (int k = 1; k < m-1;k++){
					if (!block[i][j][k]&&!vis[j][k]){
						hitExt=false;
						si=0;
						dfs(j, k, i);
						if (!hitExt) ans+=si;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
