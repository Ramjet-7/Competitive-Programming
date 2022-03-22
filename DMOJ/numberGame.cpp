#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int ans = -1;
void solve(ll n, string num){
	if (stol(num) > n) return;
	if (num=="0") num="";
	solve(n, num+'2');
	solve(n, num+'3');
	ans++;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ll n;
	cin >> n;
	solve(n, "0");
	cout << ans << '\n';
}