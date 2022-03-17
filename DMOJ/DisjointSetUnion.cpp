// Problem: https://dmoj.ca/problem/ds2
#include <bits/stdc++.h>
using namespace std;
const int MXN = 1e5+1;
int parent[MXN], sizes[MXN];
vector<int> mst;
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {sizes[i]=1; parent[i]=i;}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (Find(u)!=Find(v)){
			mst.push_back(i);
			Union(u,v);
		}
	}
	if (mst.size()!=n-1){ cout << "Disconnected Graph\n"; return 0;}
	for (int edge : mst) cout << edge << '\n';
}
