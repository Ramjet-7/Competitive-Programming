// Problem: https://dmoj.ca/problem/aac4p3
#include <bits/stdc++.h>
typedef long double ld;
using namespace std;
#define int long long
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> endpoints, slopes;
	set<ld> rep;
	int n, m;
	cin >> n >> m;
	for (int i=0; i < n; i++){
		int xi, yi;
		cin >> xi >> yi;
		endpoints.push_back({xi, yi});
	}
	for (int i = 0; i < m; i++){
		ld ki, di;
		cin >> ki >> di;
		bool found=false;
		for (ld j : rep) {
			if (j == (ld)(ki/di)) found=true;
		}
		if (!found) {
			slopes.push_back({ki, di});
			rep.insert((ki/di));
		}
	}
	int ans = 0;
	for (pair<int, int> slope : slopes){
		map<int, int> freq;
		for (pair<int, int> endpoint : endpoints){
			freq[slope.first*endpoint.first-slope.second*endpoint.second]++;
		}
		for (auto &x : freq) {
			int i=x.second;
			if (i >= 2) ans+=(i*i-i)/2;
		}
	}
	cout << ans << '\n';
	return 0;
}
