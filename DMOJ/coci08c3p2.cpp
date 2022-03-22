#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++){
        if (s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
            s.erase(s.begin()+i+1, s.begin()+i+3);
        }
    }
    cout << s << '\n';
}