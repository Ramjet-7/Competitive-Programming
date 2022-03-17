// Problem: https://dmoj.ca/problem/sac21ccp5
#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
typedef long long ll;
using namespace std;
const int MXN = 1e5+1;
int parent[MXN], sizes[MXN];
int Find(int v){
	if (v==parent[v]) return v;
	return parent[v] = Find(parent[v]);
}
void Union(int a, int b){
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
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		parent[i]=i;
		sizes[i]=1;
	}
	while (q--){
		int x, u, v;
		cin >> x;
		if (x == 1){
			cin >> u >> v;
			Union(u,v);
		} else {
			cin >> u;
			cout << sizes[Find(u)] << '\n';
		}
	}
}
