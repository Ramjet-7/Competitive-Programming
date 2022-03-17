// Problem: https://dmoj.ca/problem/ccc21s3
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MXN = 2e5+1;
vector<tuple<int, int, int>> d(MXN);
int n;
int f(int x){
	int td = 0;
	for (int i = 0; i < n; i++){
		int pi = get<0>(d[i]), wi=get<1>(d[i]), di=get<2>(d[i]);
		if (pi-di <= x && x <= pi + di){
			continue;
		}
		else if (x >= pi+di){
			td += wi*(x-pi-di);

		} else if (x <= pi-di){
			td += wi*(pi-di-x);
		}
	}
	return td;
}
int ternary_search(int l, int r) {
	int j = 0;
    while (abs(r - l) >= 3) {
		j++;
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = f(m1); 
        int f2 = f(m2); 
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
	return f((l + r)/2);
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int maxpi = -1, minpi = INT_MAX-1;
	for (int i = 0; i < n; i++){
		int pi, wi, di;
		cin >> pi >> wi >> di;
		maxpi = max(pi, maxpi);
		minpi = min(minpi, pi);
		d[i]={pi, wi, di};
	}
	cout << ternary_search(minpi, maxpi);
}
