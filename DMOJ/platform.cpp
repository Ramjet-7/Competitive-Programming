// Problem: https://dmoj.ca/problem/crci07p1
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> platforms;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b ,c;
		cin >> a >> b >> c;
		platforms.push_back({a, {b,c}});
	}
	sort(platforms.rbegin(), platforms.rend());
	int sum = 0;
	for (int i = 0; i < n; i++){
		int alt = platforms[i].first;
		int x = platforms[i].second.first;
		int y = platforms[i].second.second;
		bool xfound=false, yfound=false;
		for (int j = i+1; j < n; j++){
			if (!xfound&&x+0.5 >= platforms[j].second.first && x+0.5 <= platforms[j].second.second){
				sum+=abs(alt-platforms[j].first);
				xfound=true;
			}
			if (!yfound&&y-0.5 >= platforms[j].second.first && y-0.5 <= platforms[j].second.second){
				sum+=abs(alt-platforms[j].first);
				yfound=true;
			}
			if (xfound && yfound) break;
		}
		if (!xfound)sum+=alt;
		if (!yfound)sum+=alt;
	}
	cout << sum << '\n';
}