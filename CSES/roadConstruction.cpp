#include <bits/stdc++.h>
using namespace std;
const int MXN = 100001;
int parent[MXN], sizes[MXN];
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,x,y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		sizes[i]=1;
		parent[i]=i;
	}
	int ans = n, maxsize = 0;
	for (int i = 0; i < m; i++){
		cin >> x >> y;
		if (Find(x)!=Find(y)){
			ans--;
			cout << ans << ' ';
			Union(x,y);
		} else cout << ans << ' ';
		maxsize=max({maxsize, sizes[parent[x]],sizes[parent[y]]});
		cout << maxsize << '\n';
	}
}