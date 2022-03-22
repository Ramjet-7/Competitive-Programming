#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MOD = 4294967296;
vector<ull> pfa(34,1);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	for (int i = 0; i < 33; i++){
		pfa[i+1]=(pfa[i]%MOD*(i+1))%MOD;
	}
	int N;
	cin >> N;
	while (N--){
		ull n;
		cin >> n;
		if (n > 33) cout << "0\n";
		else cout << pfa[n] << '\n';
	}

}