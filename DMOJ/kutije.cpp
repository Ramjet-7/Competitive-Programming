// Problem: https://dmoj.ca/problem/coci21c2p2
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int parent[MAX], sizes[MAX];
int Find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q, pi;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++){
		parent[i]=i;
		sizes[i]=1;
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> pi;
			Union(j+1, pi);
		}
	}
	int a,b;
	while (q--){
		cin >> a >> b;
		if (Find(a)==Find(b)) cout << "DA\n";
		else cout << "NE\n";
	}
}
