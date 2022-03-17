// Problem: https://dmoj.ca/problem/tss17b
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll radii[186739];
int n, q;
int binarySearch(ll x){
	int low = 0, high = n-1, mid=0;
	while (low <= high) {
		mid = low + (high - low) / 2;
		if (radii[mid] == x) return mid+1;
		if (radii[mid] < x) low = mid + 1;
		else high = mid - 1;
	}
	if (radii[mid] > x) return mid;
	return mid + 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	ll r, x ,y;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		radii[i]=x*x+y*y;
	}
	sort(radii, radii+n);
	for (int i = 0; i < q; i++){
		cin >> r;
		cout << binarySearch(r*r) << '\n';
	}
}
