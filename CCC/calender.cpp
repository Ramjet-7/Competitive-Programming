#include <bits/stdc++.h>
using namespace std;
int in;
int main(){
        int day, numOfDays;
        int temp = 1;
        cin >> day >> numOfDays;
        cout << "Sun Mon Tue Wed Thr Fri Sat\n";
        for (int i = 0; i < (day-1) * 4 + 2; i++) cout << " ";
        for (int i = 0; i < 7 - day; i++) {
            cout << i+1 << "   ";
            temp = i+2.;
        }
        cout << temp << "\n";
        cout << "  ";
        for (int i = temp+1; i <= temp + 7; i++){
            if (i < 9) cout << i << "   ";
            else if (i == temp + 7) cout << i << "\n";
            else cout << i << "  ";
        }
        if (day == 7) cout << "\n  ";
        else cout << " ";
        for (int i = temp + 8; i <= temp + 14; i++){
            if (i == temp + 14) cout << i << "\n";
            else cout << i << "  ";
        }
        cout << " ";
        for (int i = temp + 15; i <= temp + 21; i++){
            if (i == temp + 21) cout << i << "\n";
            else cout << i << "  ";
        }
        if (day != 1 || numOfDays != 28){
            cout << " ";
            for (int i = temp + 22; i <= numOfDays; i++){
                if (i == 29 && day == 7) {cout << i << "\n"; break;}
                else if (i == 30 && day == 6) {cout << i << "\n"; break;}
                else if (i == numOfDays) cout << i << "\n";
                else cout << i << "  ";
            }
        } 
        if ((day == 6 && numOfDays == 31) || (day == 7 && numOfDays >= 30)) {
            cout << " ";
            for (int i = temp + 29; i <= numOfDays; i++){
                if (i==numOfDays) cout << i;
                else cout << i << "  ";
            }
            if (numOfDays > 30 && day >= 6)cout << '\n';
        }
        if (numOfDays==30&&day==7) cout << '\n';
   
}
