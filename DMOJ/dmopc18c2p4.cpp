// Problem: https://dmoj.ca/problem/dmopc18c2p4
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll m, di;
int arr[500000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ll total_sum = 0;
	for (int i = 0; i < n; i++){
		cin >> di;
		arr[i] = di;
		total_sum += di;
	}
	ll sum = arr[0];
	int left = 0, right = 0, ans = 500000;
	bool start = true;
	while (arr[left] != arr[n] && arr[right] != arr[n]){
		if (sum < m){
			right++;
			sum += arr[right];
		} else if (sum >= m){
			//cout << right << " " << left << "\n";
			//ans = right - left + 1;
			sum -= arr[left];
			ans = min(ans, right - left + 1);
			left++;
		}
		//cout << ans << ": " << sum << "\n";
	}
	if (total_sum < m) cout << "-1";
	else if (total_sum == m) cout << n;
	else cout << ans;
}
