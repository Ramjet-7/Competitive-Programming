// Problem: https://dmoj.ca/problem/mnyc16p5
#include <bits/stdc++.h>
using namespace std;
const int MAX = 150, INF = INT_MAX-1;
int prism[MAX][MAX][MAX], d[MAX][MAX][MAX];
bool exterior[MAX][MAX][MAX], processed[MAX][MAX][MAX];
priority_queue<pair<int, tuple<int, int, int>>> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z, x0, y0, z0;
	char xi;
	cin >> x >> y >> z;
	for (int i = 0; i < z; i++){
		for (int j = 0; j < y; j++){
			for (int k = 0; k < x; k++){
				if (i == 0 || i == z-1) exterior[i][j][k]=true;
				else if (j == 0 || j == y-1) exterior[i][j][k]=true;
				else if (k==0 || k==x-1) exterior[i][j][k]=true;
				cin >> xi;
				if (xi == 'J') {
					x0 = k; y0 = j; z0 = i;
				}
				prism[i][j][k]=((int)(xi)-48);
			}
		}
	}
	// Print Prism
	// for (vector<vector<char>> v2 : prism){
	// 	for (vector<char> v1 : v2){
	// 		for (char i : v1){
	// 			cout << i << ' ';
	// 		}
	// 		cout << '\n';
	// 	}
	// 	cout << '\n';
	// }
	// Grid Dijkstra
	// for (int i = 0; i < z; i++){
	// 	for (int j = 0; j < y; j++){
	// 		for (int k = 0; k < x; k++){
	// 			cout << exterior[i][j][k];
	// 		}
	// 		cout << '\n';
	// 	}
	// 	cout << '\n';
	// }
	for (int i = 0; i < z; i++){
		for (int j = 0; j < y; j++){
			for (int k = 0; k < x; k++){
				d[i][j][k]=INF;
			}
		}
	}
	int ans = INF;
	d[z0][y0][x0]=0;
	q.push({0,{z0, y0, x0}});
	while (!q.empty()){
		int x1 = get<2>(q.top().second);
		int y1 = get<1>(q.top().second);
		int z1 = get<0>(q.top().second);
		q.pop();
		if (processed[z1][y1][x1]) continue;
		processed[z1][y1][x1]=true;
		if (x1 > 0){
			int x2 = x1-1, w = prism[z1][y1][x2];
			if (d[z1][y1][x1]+w < d[z1][y1][x2]){
				d[z1][y1][x2]=d[z1][y1][x1]+w;
				q.push({-d[z1][y1][x2], make_tuple(z1, y1, x2)});
			}
		} if (x1 < x-1){
			int x2 = x1+1, w = prism[z1][y1][x2];
			if (d[z1][y1][x1]+w < d[z1][y1][x2]){
				d[z1][y1][x2]=d[z1][y1][x1]+w;
				q.push({-d[z1][y1][x2], make_tuple(z1, y1, x2)});
			}
		} if (y1 > 0){
			int y2 = y1-1, w = prism[z1][y2][x1];
			if (d[z1][y1][x1]+w < d[z1][y2][x1]){
				d[z1][y2][x1]=d[z1][y1][x1]+w;
				q.push({-d[z1][y2][x1], make_tuple(z1, y2, x1)});
			}
		} if (y1 < y-1){
			int y2 = y1+1, w = prism[z1][y2][x1];
			if (d[z1][y1][x1]+w < d[z1][y2][x1]){
				d[z1][y2][x1]=d[z1][y1][x1]+w;
				q.push({-d[z1][y2][x1], make_tuple(z1, y2, x1)});
			}
		} if (z1 > 0){
			int z2 = z1-1, w = prism[z2][y1][x1];
			if (d[z1][y1][x1]+w < d[z2][y1][x1]){
				d[z2][y1][x1]=d[z1][y1][x1]+w;
				q.push({-d[z2][y1][x1], make_tuple(z2, y1, x1)});
			}
		} if (z1 < z-1){
			int z2 = z1+1, w = prism[z2][y1][x1];
			if (d[z1][y1][x1]+w < d[z2][y1][x1]){
				d[z2][y1][x1]=d[z1][y1][x1]+w;
				q.push({-d[z2][y1][x1], make_tuple(z2, y1, x1)});
			}
		}
		if (exterior[z1][y1][x1]){
			ans=min(ans, d[z1][y1][x1]);
		}
	}
	cout << ans;
}
