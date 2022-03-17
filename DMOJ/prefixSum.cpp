// Problem: https://dmoj.ca/problem/gfssoc2j4
#include <bits/stdc++.h>
using namespace std;
int prefix[500001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q, sum=0;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
      int x;
      cin >> x;
      sum+=x;
      prefix[i+1]=sum;
    }
    while (q--){
      int a,b;
      cin >> a >> b;
      cout << sum-(prefix[b]-prefix[a-1]) << '\n';
    }
}
