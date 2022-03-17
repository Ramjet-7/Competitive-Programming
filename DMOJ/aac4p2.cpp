// Problem: https://dmoj.ca/problem/aac4p2
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long int ull;
using namespace std;
ll lights[200000], scenarios[1000000];
int n, q, ai, ti;
set<ull> pla2;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++){
		cin >> ai;
		lights[i] = ai;
	}
	for (int i = 0; i < q; i++){
		cin >> ti;
		scenarios[i] = ti;
	}
	// Construct LCM Prefix
	vector<ull> pla;
	vector<int> freq;
	vector<int> ind;
	pla.push_back(lights[0]);
	int cnt = 1;
	ll current_lcm = lcm(pla[cnt-1], lights[cnt]);
	while (current_lcm > 0 && cnt < n){
		cnt++;
		pla.push_back(current_lcm);
		current_lcm = lcm(pla[cnt-1], lights[cnt]);
	}
	cnt = 1;
	for (int i = 0; i < pla.size(); i++){
		if (pla[i] == pla[i+1]){
			cnt++;
		}
		else {
			freq.push_back(cnt);
			cnt=1;
		}
	}
	for (ull i : pla) {
		pla2.insert(i);
		//cout << i << " ";
	 }
	//cout << "\n";
	//for (int i : freq) cout << i << " ";
	ind.push_back(0);
	int sum = 0;
	for (int i = 0; i < freq.size()-1; i++){
		sum += freq[i];
		ind.push_back(sum);
	}
	//cout << "\n";
	//for (int i : ind) cout << i << " ";
	//cout << "\n";
	pla.clear();
	for (ull i : pla2) {pla.push_back(i);}
	//for (ll i : pla) cout << i << " ";
	//cout << "SIZE OF SET: " << pla2.size();
	//cout << "\n";
	for (int i = 0; i < q; i++){
		bool found=false;
		if (scenarios[i]==0) cout << "-1\n";
		else {
			for (int j = 0; j < pla.size(); j++){
				if (scenarios[i] % pla[j] != 0) {
					cout << ind[j]+1 << "\n";
					found=true;
					break;
				}
			}
			if (!found) cout << "-1\n";
		}
	}
	return 0;
}
